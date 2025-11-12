#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+15;

int lst[N],sum,zh,a[N],k,n; 
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;++i){
		lst[sum] = i;
		scanf("%d",&a[i]);
		sum^=a[i];
		if(lst[sum^k]>zh){++ans;zh = i;}
	}
	printf("%d",ans);
	return 0;
}
