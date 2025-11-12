#include<iostream>
using namespace std;
int a[10001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	
	int maxlen=-999,sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		maxlen=(a[i]>maxlen?a[i]:maxlen);
	}
	
	if(sum>2*maxlen && n>=3) cout<<1;
	else cout<<0;
	return 0;
}
