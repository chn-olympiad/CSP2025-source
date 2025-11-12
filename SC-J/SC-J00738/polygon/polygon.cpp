#include <iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio();
	{
		
		long long n;
		cin>>n;
		int a[n+3];
		int maxn=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>=maxn) max=a[i];
			
		}
		
	}
	return 0;
}