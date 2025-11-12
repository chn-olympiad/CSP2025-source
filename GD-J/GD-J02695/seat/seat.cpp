#include<bits/stdc++.h>
using namespace std;
int n,m,ran=1,score;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>score;
	for(int i=1;i<n*m;i++){
		int a;
		cin>>a;
		if(a>score)ran+=1;
	}
	int c,r;
	c=(ran-1)/n+1;
	if(c%2==1)r=(ran-1)%n+1;
	else r=n-((ran-1)%n+1)+1;
	cout<<c<<" "<<r;
	return 0;
}
