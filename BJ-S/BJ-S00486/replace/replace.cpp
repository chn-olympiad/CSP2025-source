#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N1=2e3+1,N=2e5+1,P=10;
int n,q,ls[N],sp1[N],sp2[N];
bool b1,b2,b3=1;
unsigned int hs1[N1][N1],hs2[N1][N1],ht1[N1],ht2[N1],p[N1]={1};
string s1[N],s2[N],t1,t2;
void hach(unsigned int a[],string s){
    int len=s.size();
    for(int i=0;i<len;i++){
        if(i)a[i]=a[i-1]*P;
        a[i]+=s[i]-'a';
    }
}
unsigned int query(unsigned int a[],int l,int r){
    if(l<=0)return a[r];
    return a[r]-a[l-1]*p[r-l+1];
}
int get_sp(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='b'){
            return i;
        }else if(s[i]!='a'){
            return -1;
        }
    }
    return -1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    b1=(n<=2000);
    b2=(q<=1);
    if(b1){
        for(int i=1;i<n;i++){
            p[i]=p[i-1]*P;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        ls[i]=s1[i].size();
        if(b1){
            hach(hs1[i],s1[i]);
            hach(hs2[i],s2[i]);
        }if(b3){
            sp1[i]=get_sp(s1[i]);
            sp2[i]=get_sp(s2[i]);
            if(sp1[i]==-1||sp2[i]==-1){
                b3=0;
            }
        }
        
    }
    for(int _=1;_<=q;_++){
        cin>>t1>>t2;
        if(t1==t2){
            cout<<0<<endl;
            continue;
        }
        int cnt=0,tp1,tp2;
        if(b1){
            hach(ht1,t1);
            hach(ht2,t2);
        }
        if(b3){
            tp1=get_sp(t1);
            tp2=get_sp(t2);
            if(tp1==-1||tp2==-1){
                b3=0;
            }
        }
        int len=t1.size(),l=len,r=0;
        for(int i=0;i<len;i++){
            if(t1[i]!=t2[i]){
                l=min(l,i);
                r=max(r,i);
            }
        }
        for(int i=1;i<=n;i++){
            int len2=ls[i];
            if(len2>=r-l+1){
                if(b1){
                    for(int j=max(0,r-len2+1);j<l+len2-1&&j+len2-1<len;j++){
                        if(query(hs1[i],0,len2-1)==query(ht1,j,j+len2-1)&&query(hs2[i],0,len2-1)==query(ht2,j,j+len2-1)){
                            cnt++;
                        }
                    }
                }else if(b3){
                    if(tp1-tp2==sp1[i]-sp2[i]&&sp1[i]<=tp1&&len2-sp1[i]<=len-tp1&&sp2[i]<=tp2&&len2-sp2[i]<=len-tp2){
                        if(_==909)cout<<tp1<<" - "<<tp2<<" "<<sp1[i]<<" "<<sp2[i]<<endl;
                        cnt++;
                    }
                }
                else{
                    for(int j=max(0,r-len2+1);j<l+len2-1&&j+len2-1<len;j++){
                        bool ok=1;
                        for(int k=0;k<len2;k++){
                            if(s1[i][k]!=t1[j+k]||s2[i][k]!=t2[j+k]){
                                ok=0;
                                break;
                            }
                        }
                        if(ok)cnt++;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
/*

4 2
dabcd daded
ab cd
bc de
aa bb
dabcd daded
aaaa bbbb


*/