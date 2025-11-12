#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long a=0;
	char c=getchar();
	while(c<'0' or c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	} 
	return a;
}
long long t,n,a[5][111111],sum[5],ans,tp;
priority_queue <long long>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		ans=0;tp=0;
		sum[1]=sum[2]=sum[3]=0; 
		n=read();
		for(long long i=1;i<=n;i++){
			a[1][i]=read();
			a[2][i]=read();
			a[3][i]=read();
			if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]){
				sum[1]++; 
			}else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i]){
				sum[2]++;
			}else{
				sum[3]++;
			}
			ans+=max(a[1][i],max(a[2][i],a[3][i]));
		} 
//		cout<<sum[1]<<" "<<sum[2]<<" "<<sum[2]<<endl;
//		cout<<ans<<endl;
		if(sum[1]>n/2){
			tp=1;
		}else if(sum[2]>n/2){
			tp=2;
		}else if(sum[3]>n/2){
			tp=3;
		}else{
			cout<<ans<<endl;
		}
		for(long long i=1;i<=n;i++){
			long long val=-999999999999999;
			if(a[tp][i]>=a[1][i]&&(a[tp][i]>=a[2][i]&&a[tp][i]>=a[3][i])){
				for(long long j=1;j<=3;j++){
					if(j!=tp){
						val=max(val,a[j][i]-a[tp][i]);
					}
				}
				q.push(val);
			}
		}
		for(long long i=sum[tp];i>n/2;i--){
			ans+=q.top();
			q.pop(); 
		}
		while(!q.empty())q.pop();
		if(tp)cout<<ans<<endl;
	}
	
	return 0;
} 
