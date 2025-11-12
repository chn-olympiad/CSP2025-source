#include<bits/stdc++.h>
using namespace std;
long long n,m,s[105],x,y,num;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	cin>>s[i];
	x=s[1];
	sort(s+1,s+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++)
	if(s[i]==x){
		num=i;
		break;
	}
	x=(num-1)/n+1;
	if(x&1){
		y=num%n;
		if(!y)y=n;
	}
	else y=n-num%n+1;
	cout<<x<<" "<<y;
	return 0;
}
