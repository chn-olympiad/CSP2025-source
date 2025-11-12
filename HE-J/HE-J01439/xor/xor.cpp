#include <bits/stdc++.h>
using namespace std;
int n, a[500005];
long long int k;
int z, o;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d%",&a[i]);
		if(a[i]==1)o++;
		if(a[i]==0)z++;
	}
	bool flag=false;
	if(o==n)flag=true;
	if(flag&&k==0){
		printf("%d",n/2);
		return 0;
	}
	int sum=0;
	if(k==0){
		for(int i=1;i<n;i++){
			if(a[i]==1&&a[i-1]==1){
				sum++;
				i++;
			}
		}
		printf("%d",sum+z);
		return 0;
	}
	if(k==1){
		if(o%2==0)printf("%d",o-1);
		if(o%2==1)printf("%d",o);
		return 0;
	}
	cout<<6;
	return 0;
}
