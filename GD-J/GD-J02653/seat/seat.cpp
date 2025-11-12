#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int s=a[1],b;
	sort(a+1,a+(n*m)+1,f);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			b=i;
			break;
		}
	}
	int c=1,r=1,x=1;
	b--;
	while(b--){
		if(x==1&&r+1<=n)r+=x;
		else if(x==-1&&r-1>=1)r+=x;
		else {
			c++;
			x*=-1;
		}
		
	}
	cout<<c<<' '<<r;
	return 0;
} 
