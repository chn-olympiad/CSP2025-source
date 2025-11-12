#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum,ans;
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++)	cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==ans){
			ans=i;
			break;
		}
	}
	cout<<(ans+n-1)/n<<' ';
	if((ans+n-1)/n%2)	cout<<(ans-1)%n+1;
	else	cout<<n-((ans-1)%n);
	return 0;
}
