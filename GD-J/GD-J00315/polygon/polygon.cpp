#include <iostream>
#include <cstdio>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int maxx=-1,sum=0;
			for(int q=i;q<=j;q++){
				if(a[q]>maxx)maxx=a[q];
				sum+=a[q];
			}
			if(j-i+1>=3&&sum>maxx*2)num++;
			num%=998244353;
		}
	}
	cout<<num;
	return 0;
}
