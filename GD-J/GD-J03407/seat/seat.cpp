#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r,st=0;
	cin>>r;
	for(int i=1;i<n*m;i++)
	{
		int x;
		cin>>x;
		if(x>r)st++;
	}
	if((st/m+1)%2)cout<<(st/m+1)<<' '<<st%n+1;
	else cout<<(st/m+1)<<' '<<n-st%n;
	return 0;
}
 
