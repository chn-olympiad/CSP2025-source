#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::freopen;
bool compare(int a,int b)
{return a>b;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,a[200];
	cin>>n>>m;
	cin>>r;
	a[0]=r;
	for(int i=1;i<n*m;i++)
		cin>>a[i];
	std::sort(a,a+n*m,compare);
	int sub;
	for(int i=0;i<n*m;i++){
		//cout<<a[i]<<' ';
		if(a[i]==r){
			sub=i;
			break;
		}
	}
	int x=sub/n+1,y=sub%n+1;
	if(x%2==0)
		y=n-y+1;
	cout<<x<<' '<<y;
	return 0;
}