#include<bits/stdc++.h>
using namespace std;

const int N=5000;
int a[N+10];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(n==3){
		int maxv=max(a[1],max(a[2],a[3]));
		int sum=a[1]+a[2]+a[3];
		if(sum>2*maxv){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	


	return 0;
}
