#include<bits/stdc++.h>
using namespace std;
int a[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s,s1,maxx=0,sum;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		s=s1=sum=0;
		for(int j=1;j<=i;j++){
			s^=a[j];
		}
		for(int j=i+1;j<=n;j++){
			s1^=a[j];
		}
		if(s==k){
			sum++;
		}
		if(s1==k){
			sum++;
		}
		if(sum>maxx){
			maxx=sum;
		}
	}
	printf("%d",maxx);
	return 0;
}
