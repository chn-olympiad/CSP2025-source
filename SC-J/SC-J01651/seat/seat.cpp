#include<bits/stdc++.h>
using namespace std;
int n,m;
int lr=0,sc;
vector<int> v;
int a[15][15]={0};
int pos=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>lr;
	v.push_back(lr);
	for(int i=1;i<n*m;i++){
		cin>>sc;
		v.push_back(sc);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n*m;i++)
	{
		if(v[i]==lr)
		{
			pos=i+1;
			break;
		}
	}
	int k=(pos/(2*n));
	int q=(pos%(2*n));
	if(q==0)
		cout<<2*k<<" "<<1<<endl;
	else if(q<=n)
		cout<<2*k+1<<" "<<q<<endl;
	else
		cout<<2*k+2<<" "<<2*n-q+1<<endl;
	return 0;
} 