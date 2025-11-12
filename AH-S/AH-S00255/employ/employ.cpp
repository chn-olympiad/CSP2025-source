#include<bits/stdc++.h>
using namespace std;
int n,m,x,tp,a[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
	}
	//~ int sum=0,tp1=a[0];
	//~ for(int i=1;i<=n;i++){
		//~ sum+=a[i];
		//~ if(sum>n-k){
			
		//~ }
	//~ }
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	//~ sort(a+1,a+n+1);
	//~ for(int i=1;i<=n;i++){
		
	//~ }
	return 0;
}
