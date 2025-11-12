#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int a[N],q[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q[i]=q[i-1]^a[i];
	}
	int cnt=0,num=0;
	for (int i=1;i<=n;i++)
		for (int j=num;j<i;j++)
			if ((q[j]^q[i])==k){
				cnt++,num=i;
				break;
			}
	printf("%d",cnt);
}
