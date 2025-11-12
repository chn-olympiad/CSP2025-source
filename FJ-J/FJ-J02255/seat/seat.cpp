#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int n,m,rcj,anslie;
	cin>>n>>m;
	int x[105];
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>rcj;
	x[1]=rcj;
	for(int i=2;i<=n*m;i++)
	{
		cin>>x[i];
	}
	sort(x+1,x+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(x[i]==rcj)
		{
			anslie=(int)(ceil((i+0.0)/n));
			cout<<anslie<<" ";
			if(anslie%2==1){
				cout<<i-(anslie-1)*n;//
			}
			if(anslie%2==0){
				cout<<(n+1)-(i-(anslie-1)*n);
			}
		}
	}
	return 0;
}
