#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
struct stu{
	int d1;
	int d2;
	int d3;
}a[N];
int n;
int ans=-1;
int cnt_1;
int cnt_2;
int cnt_3;
int res[N];
int b[N];
void dfs(int st){
	if(cnt_1>n/2||cnt_2>n/2||cnt_3>n/2) return;
	if(st==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(res[i]==1){
				sum+=a[i].d1;
			}
			else if(res[i]==2){
				sum+=a[i].d2;
			} 
			else{
				sum+=a[i].d3;
			}
		}
		ans=max(ans,sum);
	}
	cnt_1++;
	res[st]=1;
	dfs(st+1);
	cnt_1--;
	cnt_2++;
	res[st]=2;
	dfs(st+1);
	cnt_2--;
	cnt_3++;
	res[st]=3;
	dfs(st+1);
	cnt_3--;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=-1;
		cnt_1=0;
		cnt_2=0;
		cnt_3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			b[i]=a[i].d1;
		}
		if(n<=10)dfs(1);
		else{
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}