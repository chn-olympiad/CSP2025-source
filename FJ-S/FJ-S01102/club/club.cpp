#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
int t,n,a[100010][3],c[100010],cnt[3],ans;
priority_queue<int>q;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		cnt[0]=0;
		cnt[1]=0;
		cnt[2]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				a[i][j]=read();
			}
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				c[i]=0;
				cnt[0]++;
				ans+=a[i][0];
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				c[i]=1;
				cnt[1]++;
				ans+=a[i][1];
			}
			else{
				c[i]=2;
				cnt[2]++;
				ans+=a[i][2];
			}
		}
		int k=-1;
		for(int i=0;i<3;i++){
			if(cnt[i]>n/2)k=i;
		}
		for(int i=1;i<=n;i++){
			if(c[i]==k){
				int t=1e9;
				for(int j=0;j<3;j++){
					if(j!=k){
						t=min(t,a[i][k]-a[i][j]);
					}
				}
				q.push(-t);
			}
		}
		if(k!=-1){
			for(int i=0;i<cnt[k]-n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}
		cout<<ans<<endl;
		while(!q.empty())q.pop();
	}
	return 0;
}
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
