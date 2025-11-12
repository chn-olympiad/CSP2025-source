#include<bits/stdc++.h>
using namespace std;

int n;
long long k;
int a[5000001];
bool b[500001][500001];
int ans=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	memset(b,false,sizeof(b));

	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	long long u; 
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			u=a[i];
			for(int p=i+1;p<=j;p++)
				u^=a[p];
			if(u==k)
				b[i][j]=true;
			ans++;
		}
	printf("%d",ans);		
	return 0;
}
