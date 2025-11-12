#include<iostream>
using namespace std;
long long n,m,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	for(int i=m;i>=1;--i)
		ans*=i;
	printf("%lld\n",ans);
	return 0;
}
