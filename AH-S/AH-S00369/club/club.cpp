#include<bits/stdc++.h>
using namespace std;
const int N=300010;
int t,n,a[N][3],cnt[4],sum;
void dfs(int x,int ss){
    if(x>n){
        sum=max(sum,ss);
        return;
    }
    for(int i=1;i<=3;i++)
        if(cnt[i]<n/2){
            cnt[i]++;
            dfs(x+1,ss+a[x][i]);
            cnt[i]--;
        }
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                cin>>a[i][j];
        dfs(1,0);
        cout<<sum<<endl;
	}
	return 0;
}
