#include <iostream>
#include <cstdio>
using namespace std;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num=0,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		sum=sum^a[i];
		if(sum==k){
			num++;
			sum=0;
		}
	}
	cout<<num;
	return 0;
}
