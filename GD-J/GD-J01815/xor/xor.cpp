#include <iostream>
using namespace std;

const int maxn=5*100000+10;
long long k;
long long a[maxn];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;	
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		long long sum=0,r=i;
		for(int j=0;j<=n;j++){
			sum^=a[i+j];
			if(sum==k) {
				r=i+j;
				cnt++;
				break;
			}
		}
		i=r;
	}
	cout<<cnt<<endl;
	return 0;
}
