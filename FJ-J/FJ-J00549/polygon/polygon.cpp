#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll max(int a,int b){
	if(a>b)return a;
	el
}
ll choose(int a,int b,int c){
	ll maxn=max(a,max(a,b));
	if (maxn*2<a+b+c)return true;
	else return false;
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	ll n,cnt=0;
	cin>>n;
	ll arr[n+1];
	for(int i=1;i<=n;i++)cin>>arr[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(choose(i,j,k))cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
