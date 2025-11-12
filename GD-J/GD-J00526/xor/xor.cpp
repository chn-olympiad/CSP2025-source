#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000005],b[1000005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i =1;i<=n;i++) scanf("%d",&a[i]);
	b[0]=0;
	b[1]=a[1];
	int cnt=0;
	for(int i =2;i<=n;i++) b[i]=b[i-1]^a[i];
	for(int i =1;i<=n;i++){
		for(int j =cnt;j<i;j++){
			int x=b[i]^b[j];
			if(x==m){
				cnt=i;
				ans++;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
