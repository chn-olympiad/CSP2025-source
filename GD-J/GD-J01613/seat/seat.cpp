#include<bits/stdc++.h>
using namespace std;
long long n,m,k,g,ans;
long long a[105],b[105][105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) k=a[i];
	}
	g=n*m;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		ans++;
		if(a[i]==k){
			cout<<(ans-1)/n+1<<" ";
			if(((ans-1)/n+1)%2==1) cout<<(ans-1)%n+1;
			else cout<<n-((ans-1)%n+1)+1;
			return 0;
		}
	}
	
	return 0;
}
