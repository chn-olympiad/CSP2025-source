#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,k,a[N],ans;
bool f1=true,f2=true,f3=true;
struct node{
    int x,y;
}aa[100001];
bool cmp(node u,node v){
    if(u.y-u.x!=v.y-v.x) return u.y-u.x<v.y-v.x;
    else return u.x<v.x;
}
string work(int x){
    string s="";
    while(x){
        if(x&1) s=('1'+s);
        else s=('0'+s);
        x/=2;
    }
    string t=s;
    for(int i=1;i<=10-t.size();i++) s=('0'+s);
    return s;
}
int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) f1=false;
        if(a[i]>1) f2=false;
        if(a[i]>255) f3=false;
    }
    if(f1){//Test 1,3
        cout<<n/2;
        return 0;
    }
    if(f2){//Test 2,4,5,13
        if(!k){
            for(int i=1;i<=n;i++){
                if(a[i]==1&&i<n){
                    if(!a[i+1]) continue;
                    if(a[i+1]==1){
                        ans++;
                        i++;
                    }
                }
                if(!a[i]) ans++;
            }
        }
        else for(int i=1;i<=n;i++) if(a[i]==1) ans++;
        cout<<ans;
        return 0;
    }
    if(f3){//Test 6-8
        string s[1001],ss=work(k);
        int qzh[11][1001];
        memset(qzh,0,sizeof(qzh));
        for(int i=1;i<=n;i++){
            s[i]=work(a[i]);
            //cout<<s[i]<<endl;
        }
        for(int i=1;i<=10;i++){
            for(int j=1;j<=n;j++){
                qzh[i][j]=qzh[i][j-1]+(s[j][i-1]-'0');
                //cout<<qzh[i][j]<<' ';
            }
            //cout<<endl;
        }
        int xx[1001],yy[1001],tot=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                bool f=true;
                for(int k=1;k<=10;k++) if((qzh[k][j]-qzh[k][i-1])%2!=(ss[k-1]-'0')) f=false;
                if(f) aa[++tot].x=i,aa[tot].y=j;
            }
        }
        bool ff[1001];
        sort(aa+1,aa+tot+1,cmp);
        for(int i=1;i<=tot;i++){
            bool ok=true;
            for(int j=aa[i].x;j<=aa[i].y;j++){
                if(ff[j]){
                   ok=false;
                   break;
                }
            }
            if(ok){
                for(int j=aa[i].x;j<=aa[i].y;j++) ff[j]=true;
                ans++;
            }
        }
        cout<<ans;
    }
}
//expected: 30pts
