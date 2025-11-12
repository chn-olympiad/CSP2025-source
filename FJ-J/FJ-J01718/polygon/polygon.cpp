#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
const int MAXN=5005;
const int mod=998244353;
int n;
int a[MAXN];
int sum,flag[25],cnt=0;
int ans=0;
bool check(){
	if (cnt<=2) return false; 
	int maxn=0;
	for (int i=1;i<=n;i++) if (flag[i]) maxn=max(maxn,a[i]);
	return maxn*2<sum;
}
void dfs(int p){
	if (p>n){
		if (check()==true) {
			ans=(ans+1)%mod;
		}
		return;
	}
	dfs(p+1);
	flag[p]=true;
	sum+=a[p];
	cnt++;
	dfs(p+1);
	flag[p]=false;
	sum-=a[p];
	cnt--;
}
bool cmp(int x,int y){return x<y;}
ll s[10005];
ll over_sum=0;
ll res=0,tmp_sum=0,last;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n<=20){
		// special : n<=20
		dfs(1);
		cout<<ans%mod<<endl;
	}
	else {
		sort(a+1,a+n+1,cmp);
		int maxn=a[n];
		s[0]=1;
		last=a[3]*2;
		for (int i=1;i<=n;i++){
			for (int j=last+1;j<=a[i]*2;j++) tmp_sum=(tmp_sum-s[j]+mod)%mod;
			last=a[i]*2;
			over_sum=(over_sum*2)%mod;
			for (int j=maxn*2;j>=maxn*2-a[i]+1;j--){
				over_sum=(over_sum+s[j])%mod;
			}
			for (int j=maxn*2;j>=a[i];j--){
				if (a[i]*2<j) tmp_sum=(tmp_sum+s[j-a[i]])%mod;
				s[j]=(s[j]+s[j-a[i]])%mod;
			}
			if (i<=2) continue;
			res=(res+tmp_sum)%mod;
//			cout<<over_sum<<" "<<tmp_sum<<" "<<res<<" "<<i<<" "<<a[i]<<endl;
//			for (int j=0;j<=maxn*2;j++) cout<<s[j]<<" ";
//			cout<<endl;
		}
		cout<<(res+over_sum)%mod;
	}
	return 0;
}
//rp++;

