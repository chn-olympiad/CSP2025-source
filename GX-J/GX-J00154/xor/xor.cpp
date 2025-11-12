#include<iostream>
using namespace std;
int a[500002];
long long sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)cin>>a[i];
	int b=0;
	for (int i=1;i<=n;i++){
		int num=0;
		for (int t=i;t>b;t--){
			num=num^a[t];
			if (num==k){
				b=i;
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
