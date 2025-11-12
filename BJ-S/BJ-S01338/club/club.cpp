#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=100005;
int T,n;
int a[MAXN][4];
int maxn[MAXN],vis[MAXN];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int n1,n2,n3;
		n1=n2=n3=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
		}
		int ans=0,ans1,ans2,ans3;
		ans1=ans2=ans3=INT_MIN;
		for(int i=1;i<=n;i++){
			maxn[i]=max(a[i][1],max(a[i][2],a[i][3]));
			n1+=(maxn[i]==a[i][1]),n2+=(maxn[i]==a[i][2]),n3+=(maxn[i]==a[i][3]);
			ans+=maxn[i];
		}
		//cout<<ans<<" "<<n1<<" "<<n2<<" "<<n3<<endl;
		priority_queue<int>q;
		if(n1>n/2){
			ans1=ans;
			for(int i=1;i<=n;i++){
				if(a[i][1]!=maxn[i])continue;
				q.push(max(a[i][2]-maxn[i],a[i][3]-maxn[i]));
			}
			while(n1>n/2){
				ans1+=q.top();
				q.pop();
				n1--;
			}
		}
		while(!q.empty())q.pop();
		if(n2>n/2){ 
			ans2=ans;
			for(int i=1;i<=n;i++){
				if(a[i][2]!=maxn[i])continue;
				q.push(max(a[i][1]-maxn[i],a[i][3]-maxn[i]));
			}
			while(n2>n/2){
				ans2+=q.top();
				q.pop();
				n2--;
			}
		}
		while(!q.empty())q.pop();
		if(n3>n/2){
			ans3=ans;
			for(int i=1;i<=n;i++){
				if(a[i][3]!=maxn[i])continue;
				q.push(max(a[i][1]-maxn[i],a[i][2]-maxn[i]));
			}
			while(n3>n/2){
				ans3+=q.top();
				q.pop();
				n3--;
			}
		}
		if(ans1!=INT_MIN||ans2!=INT_MIN||ans3!=INT_MIN)cout<<max(ans1,max(ans2,ans3))<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
