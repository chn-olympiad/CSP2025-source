#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,q;
struct box{
    string x,z;
    string y1,y2;
}k[200005]={{"","","",""}};
string t1,t2;
int l(string s){
    return s.size();
}
bool cmp(box x,box y){
    return l(x.y1)<l(y.y1);
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        int L=l(s1);
        int ft,bc;
        for(int j=0;j<L;j++){
            if(s1[j]!=s2[j]){
                ft=j;
                break;
            }
        }
        for(int j=L-1;j>=0;j--){
            if(s1[j]!=s2[j]){
                bc=j;
                break;
            }
        }
        for(int j=0;j<ft;j++){
            k[i].x=k[i].x+s1[j];
        }
        for(int j=bc+1;j<l(s1);j++){
            k[i].z=k[i].z+s1[j];
        }
        for(int j=ft;j<=bc;j++){
            k[i].y1=k[i].y1+s1[j];
            k[i].y2=k[i].y2+s2[j];
        }
        //cout<<"k["<<i<<"].x:"<<k[i].x<<endl;
        //cout<<"k["<<i<<"].z:"<<k[i].z<<endl;
        //cout<<"k["<<i<<"].y1:"<<k[i].y1<<endl;
        //cout<<"k["<<i<<"].y2:"<<k[i].y2<<endl;
    }
    sort(k+1,k+1+n,cmp);
    for(int kkkk=0;kkkk<q;kkkk++){
        cin>>t1>>t2;
        int L=l(t1);
        if(L!=l(t2)){
            cout<<0<<endl;
            continue;
        }
        string a="",b="";
        int ft,bc;
        for(int i=0;i<L;i++){
            if(t1[i]!=t2[i]){
                ft=i;
                break;
            }
        }
        for(int i=L-1;i>=0;i--){
            if(t1[i]!=t2[i]){
                bc=i;
                break;
            }
        }
        for(int i=ft;i<=bc;i++){
            a=a+t1[i];
            b=b+t2[i];
        }
        //cout<<"a:"<<a<<endl;
        //cout<<"b:"<<b<<endl;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(l(k[i].y1)>l(a)) break;
            if(k[i].y1!=a||k[i].y2!=b) continue;
            if(l(k[i].z)>l(t1)-1-bc) continue;
            if(l(k[i].x)>ft) continue;
            bool flg=1;
            for(int j=ft-1;j>=ft-l(k[i].x);j--){
                if(t1[j]!=k[i].x[j-ft+l(k[i].x)]){
                    flg=0;break;
                }
            }
            if(!flg) continue;
            for(int j=bc+1;j<=bc+l(k[i].z);j++){
                if(t1[j]!=k[i].x[j-bc-1]){
                    flg=0;
                    break;
                }
            }
            if(!flg) continue;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
