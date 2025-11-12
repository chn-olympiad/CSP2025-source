#include<bits/stdc++.h>
using namespace std;
int n,mx,h,l[5005];
long long m[5005],num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
	}
	sort(l+1,l+1+n);
	if(n==3){
		if(l[1]+l[2]>l[3])puts("1");
		else puts("0");
		return 0;
	}
	m[0]=1;
	for(int i=1;i<=n;i++){// meiju l
		for(int j=h;j>=0;j--){//h:have number max place
			if(m[j]!=0&&m[j]>m[i]){
				int k=l[j]+l[i];
				if(l[j]+l[i]>l[n])k=n+1;
				m[k]+=m[j];
				h=max(h,k);
			}
		}
	}
	for(int i=1;i<=n;i++){
		num=(num+(m[i]-1)*(i-1))%998244353;
	}
	printf("%lld",num+1);
	return 0;
}
