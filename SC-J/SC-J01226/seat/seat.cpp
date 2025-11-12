#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[121]={0},num=0;cin>>n>>m>>a[1];for(int i=2;i<=n*m&&cin>>a[i];i++)num+=(a[1]<a[i]);//A前面的人是第num个
	int l=num/n+1,h=num%n+1; 
	cout<<l<<" "<<(l%2?h:n-h+1);
	return 0;
}