#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	vector<long long> a(n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	vector<long long> qz;
	qz.push_back(0);
	for(int i=1;i<=n;i++) qz.push_back(qz[i-1]^a[i]);
	int cnt=0,flag=0;
	int i,j;
	for(i=1;i<=n;i+=j-i+1){
		for(j=i;j<=n;j++){
			if((qz[j]^qz[i-1])==k){
				cnt++;
				flag=1;
				break;
			}
		}
		if(flag==0) j=i;
	}
	cout<<cnt;
	return 0;
}
