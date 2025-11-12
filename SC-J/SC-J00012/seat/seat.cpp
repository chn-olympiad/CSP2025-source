#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[105]={};
	int sum=0;
	int a,b;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	for(int i=2;i<=n*m;i++){
		if(s[1]<s[i]) sum++;
	}
	if(sum+1<=n) a=1;
	else if(sum+1>n) a=(sum+1)/n+1;
	if(a%n==0) b=sum+1-a;
	else if(sum+1<m) b=1;
	else if((sum+1)%2==0) b=m;
	else b=(sum+1)%m+1;
	if(b>m) b=b%m;
	cout<<a<<"  "<<b;
	return 0;
}