#include<bits/stdc++.h>
using namespace std;

int t,n,ans,m[5],a[100005][5];

void f(int pos,int sum){
	if(pos>n){
		ans=(ans<sum?sum:ans);
		return;
	}
	for(int i=1;i<=3;++i){
		if(m[i]<n/2){
			++m[i];
			f(pos+1,sum+a[pos][i]);
			--m[i];
		}
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=-1;
		m[1]=0,m[2]=0,m[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		f(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
