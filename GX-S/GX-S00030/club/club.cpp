#include <bits/stdc++.h>
using namespace std;
int a[1000001][4];
int sum[10];
int n,cnt=0,ans=-1;
void bfs(int x){
    for(int i=1;i<=3;i++){
        if(sum[i]<n/2){
            sum[i]++;
            cnt+=a[x][i];
            bfs(x+1);
            ans = max(ans,cnt);
            cnt=a[x][i]+cnt;
            sum[i] = sum[i]-1;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int s;
    cin>>s;
    for(int i=1;i<=s;i++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
           for(int j=1;i<=3;j++{
			   cin>>a[i]a[j];
		   }
        }
        bfs(1);
        cout<<ans<<endl;
        ans=-1,cnt=0;
        sum[1]=0;
        sum[2]=0;
        sum[3]=0;
    }
    return 0;
}
