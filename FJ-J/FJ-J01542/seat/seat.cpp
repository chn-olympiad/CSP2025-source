#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,b,m,i,k,c,a,ans=1;
	cin>>n>>m>>k;
	for(i=1;i<=n*m-1;i++){
		cin>>a;
		if(a>k){
			ans+=1;
		}
	}
	b=ans/n;
	c=ans%m;
	if(b%2==0&&c==0){
		cout<<b<<" "<<1;
		return 0;
	}
	if(b%2==1&&c==0){
		cout<<b<<" "<<m;
		return 0;
	}
	if(b%2==0){
		cout<<b+1<<" "<<c;
		return 0;
	}
	if(b%2==1){
		cout<<b+1<<" "<<m-c+1;
		return 0;
	}
}