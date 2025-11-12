#include <bits/stdc++.h>
using namespace std;
int n,m,s[101],x,y,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		if(i==1) ans=s[i];
	}
	sort(s+1,s+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		x=(i-1)/m+1;
		if(((i-1)/m)%2==0) y=i%m;
		else y=m-(i%m)+1;
		if(y==0) y=m;
		else if(y==m+1) y=1;
		if(s[i]==ans){
			cout<<x<<" "<<y<<endl;
			break;
		}
	}
	return 0;
}
