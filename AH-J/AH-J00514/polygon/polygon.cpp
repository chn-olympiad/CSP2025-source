#include<iostream>
#include<algorithm>
using namespace std;
const int MOD=998244353;
int a[5001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3){
		if(a[1]+a[2]+a[3]>2*(min(a[1],min(a[2],a[3])))){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	unsigned long long sum=n*(n-1)*(n-2);
	n-=2;
	while(n--){
		unsigned long long p=sum;
		sum=sum*n+p;
	}
	cout<<sum;
    return 0;
}
