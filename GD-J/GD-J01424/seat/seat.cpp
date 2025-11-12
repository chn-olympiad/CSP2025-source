#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+10],s;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	s=a[0];
	sort(a,a+n*m,cmp);
	int i=0;
	for(;i<n*m;i++){
		if(a[i]==s)break;
	}
	i++;
	int x,y;
	x=i/n;
	y=i%n;
	if(y==0){
		if(x%2==0)cout<<x<<" "<<1;
		else cout<<x<<" "<<n;
	}
	else{
		x++;
		if(x%2==0)cout<<x<<" "<<n-y+1;
		else cout<<x<<" "<<y;
	}
	return 0;
 } 
