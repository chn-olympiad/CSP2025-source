#include<bits/stdc++.h>
using namespace std;

int n,m,a[10005],x,y;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int jl=a[1];
	sort(a+1,a+n*m+1);
	for(int s=1,i=n*m;i>=1;i--,s++){
		if(a[i]==jl){
			jl=s;
			break;
		}
	}
	x=(jl+n-1)/n;
	if(x%2==1)y=(jl-1)%n+1;
	else y=m-(jl-1)%n;
	cout<<x<<" "<<y;
	return 0;
} 