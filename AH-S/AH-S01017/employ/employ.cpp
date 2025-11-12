#include "iostream"
using namespace std;
long long s=1,sum;
long long mod=998224353;
int n,m;
string t;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	sum=n;
	cin>>t;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	while(sum){
		s*=sum;
		s%=mod;
		--sum;
	}
    cout<<s;
	return 0;
}
