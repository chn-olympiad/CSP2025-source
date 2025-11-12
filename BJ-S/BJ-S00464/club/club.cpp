#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,a[N][4],d[N],num[4],ans;
int T;
int s[N],t;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        memset(s,0,sizeof(s));
        memset(num,0,sizeof(num));
        memset(d,0,sizeof(d));
        t=0;
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1,mx=0;j<=3;j++){
                cin>>a[i][j];
                if(mx<a[i][j]){
                    mx=a[i][j];
                    d[i]=j;
                }
            }
            num[d[i]]++;
            ans+=a[i][d[i]];
        }
        for(int k=1;k<=3;k++){
            if(num[k]>n/2){
                for(int i=1;i<=n;i++){
                    if(d[i]==k){
                        s[++t]=max(a[i][k%3+1],a[i][(k+1)%3+1])-a[i][k];
                    }
                }
                sort(s+1,s+t+1,cmp);
                for(int i=1;i<=t;i++){
                    num[k]--;
                    ans+=s[i];
                    if(num[k]==(n/2))break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}