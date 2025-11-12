#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y,c=1;
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<n*m;i++){
	 	cin>>y;
	 	if(y>x)
	 		c++;
}
	int a=(c+n-1)/n;
	cout<<a<<" ";
	if(a%2==1)
		cout<<c-((a-1)*n);
	else
		cout<<n-(c-((a-1)*n))+1;
	return 0;
} 

