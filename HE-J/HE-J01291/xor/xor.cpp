#include<bits/stdc++.h>
using namespace std;
int main(){
	//feropen("xor.in","r",stdin);
	//feropen("xor.out","w",stdout);
	long long n,m,num=0;
	cin>>n>>m;
	vector<int>a(n+1);
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			long long sum=0;
			for(long long z=i;z<=j;z++){
				sum^=a[z];
			}
			if(sum==m){
				num++;
				i=j;
				break;
			}
		}
	}
	cout<<num;
	return 0;
}
