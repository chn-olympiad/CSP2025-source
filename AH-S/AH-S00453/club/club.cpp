#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int T;
int n;
int a[100005][4];
int d[201][201][201];
priority_queue<int> q;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        }if(n<=200){
            memset(d,0,sizeof(d));
            int maxn=-1;
            for(int i=0;i<=n/2;i++){
                for(int j=0;j<=n/2;j++){
                    for(int k=0;k<=n/2;k++){
                        if(i+j+k==n){
                            maxn=max(maxn,d[i][j][k]);
                            break;
                        }
                        if(i+k+j>n){
                            break;
                        }int now=i+j+k+1;
                        d[i+1][j][k]=max(d[i+1][j][k],d[i][j][k]+a[now][1]);
                        d[i][j+1][k]=max(d[i][j+1][k],d[i][j][k]+a[now][2]);
                        d[i][j][k+1]=max(d[i][j][k+1],d[i][j][k]+a[now][3]);
                    }
                }
            }cout<<maxn<<endl;
        }else{
            ull cnt=0;
            for(int i=1;i<=n;i++){
                q.push(a[i][1]);
            }for(int i=1;i<=n/2;i++){
                cnt+=q.top();
                q.pop();
            }cout<<cnt<<endl;
        }
    }
    return 0;
}
