#include<bits/stdc++.h>
using namespace std;
int a[500007];
int m[500007];
long long k;
int ans,n;
int b[25000007][2];
void put(int l,int r){
	for(int i=l;i<=r;i++){
		m[i]=1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int u=0;

	for(int i=1;i<=n;i++){
		int cnt=a[i];
		if(a[i]==k){
			++u;
			b[u][0]=i;
			b[u][1]=i;
		}
		for(int j=i+1;j<=n;j++){
			cnt=cnt xor a[j];
			if(cnt==k){
				++u;
				b[u][0]=i;
				b[u][1]=j;
			}
		}
	}
//	for(int i=1;i<=u;i++){
//		printf("%d  %d\n",b[i][0],b[i][1]);
//	}
//	int mx=-123123;
//	for(int i=1;i<=u;i++){
//		
//		for(int j=1;j<=n;i++){
//			
//		}
//	}
	printf("%d",u/2);
	return 0;
}
