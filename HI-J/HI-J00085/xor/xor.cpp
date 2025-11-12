#include<bits/stdc++.h>
using namespace std;
int a[600000];
bool f[600000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int cnt=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			cnt++;
			f[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0&&f[i+1]==0){
			a[i+1]=a[i]^a[i+1];
			if(a[i+1]==k){
				cnt++;
				i+=2;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
