#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
const int N=5e3+10;
int n;
int arr[N];
int add(int b,int sum){
	if(b==0)return sum;
	return add(b-1,sum*b*(b-1));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&arr[i]);
	if(n==3)
		if(arr[1]+arr[2]+arr[3]<=max(max(arr[1],arr[2]),arr[3]))
			printf("0");
		else printf("1");
	else printf("%d",add(n,1));
	return 0;
}
