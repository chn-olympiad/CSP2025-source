#include<bits/stdc++.h>
using namespace std;
int a[10000000];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	int maxl=a[2];
	if(sum>2*maxl) cout<<"1";
	else cout<<"0";
	
	
}
