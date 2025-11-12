#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll m,n;
ll a[1000010];
ll sit[30][30];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll R=a[1];
	ll b;
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){ 
			b=i;
			break;
		}
	}
	ll c=b/n;
	ll d=b%n;
	if(c%2==1 && d==0){
		cout<<c<<" "<<n;
	}
	else if(c%2==0 && d==0){
		cout<<c<<" "<<1;
	}
	else if(c%2==1 && d!=0){
		cout<<c+1<<" "<<n-d+1;
	}
	else if(c%2==0 && d!=0){
		cout<<c+1<<" "<<d;
	}
	
	return 0;
}