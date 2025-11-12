#include<bits/stdc++.h>
using namespace std;
long long ans;
int a[5050];
int n;
void dfs(){
	for(int i=n;i>=1;i--){
		int cnt=0,t=0;
		for(int j=1;j<=i;j++){
			cnt+=a[j];
			if(cnt>a[i]){
				ans+=1+i-j;
				t++;
				cnt-=a[t];
			} 
		} 
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs();
	cout<<ans%998244353<<endl;
	return 0;
}