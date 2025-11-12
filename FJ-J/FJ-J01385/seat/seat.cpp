#include<bits/stdc++.h>
using namespace std;
int n,m,s[1000],a,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	a=s[1];
	sort(s+1,s+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(s[i]==a){
			b=n*m-i+1;
			break;
		}
	}
	cout<<(b-1)/n+1<<' ';
	if(((b-1)/n+1)%2==0){
		cout<<n-((b-1)%n);
	}else{
		cout<<(b-1)%n+1;
	}
	return 0;
}
