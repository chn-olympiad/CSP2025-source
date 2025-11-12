#include<bits/stdc++.h>
using namespace std;
int n,m,k,i,s[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;m*=n;
	for(i=1;i<=m;i++)
	cin>>s[i];
	k=s[1];
	sort(s+1,s+1+m);
	for(i=1;i<=m;i++)
	if(s[i]==k){k=m-i+1;break;}
	i=(k-1)/n+1;
	cout<<i<<' ';
	if(i%2)cout<<(k-1)%n+1;
	else cout<<n-(k-1)%n;
	return 0;
}
