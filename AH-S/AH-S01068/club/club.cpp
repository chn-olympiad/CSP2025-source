#include<bits/stdc++.h>
using namespace std;
long long T,n,a[4][100005],x[4],c[100005],d[100005],ans;
priority_queue<long long,vector<long long>,greater<long long> > q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=x[1]=x[2]=x[3]=0;
		for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[1][i],&a[2][i],&a[3][i]);
			if(a[1][i]>=max(a[2][i],a[3][i])){
				x[1]++;
				q[1].push(a[1][i]-max(a[2][i],a[3][i]));
				ans+=a[1][i];
			}
			else if(a[2][i]>=a[3][i]){
				x[2]++;
				q[2].push(a[2][i]-max(a[1][i],a[3][i]));
				ans+=a[2][i];
			}
			else{
				x[3]++;
				q[3].push(a[3][i]-max(a[2][i],a[1][i]));
				ans+=a[3][i];
			}
		}
		for(int i=1;i<=3;i++)
			for(int j=1;j<=x[i]-n/2;j++){
				ans-=q[i].top();
				q[i].pop();
			}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	//Ren5Jie4Di4Ling5%
}
