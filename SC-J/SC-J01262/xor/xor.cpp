#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define ptc putchar
using namespace std;
const int N=5e5+7;
int n,k;
int a[N];
int f[N],maxn[N];
int maxna;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		maxna=max(maxna,a[i]);
	}
	if(maxna==1){
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++) cnt+=a[i];
			printf("%d\n",cnt);
			return 0;
		}
		if(k==0){
			int cnt=0,l=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					++cnt;
					cnt+=l/2;
					l=0;
				}
				else ++l;
			}
			cnt+=l/2;
			printf("%d\n",cnt);
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j;j--){
			cnt^=a[j];
			if(cnt==k){
				f[i]=maxn[j-1]+1;
				break;
			}
		}
		maxn[i]=max(maxn[i-1],f[i]);
	}
	printf("%d\n",maxn[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}