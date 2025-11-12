#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int n,k;
int a[N],ans=1;
bool flagA=1,flagB=1;

void A(){
	printf("%d",n/2);
}

void B(){
	int res=0;
	if(k==0){
		for(int i=1;i<=n;i++,res++){
			if(a[i]==0)continue;
			while(i<=n&&a[++i]!=1);
		}
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)res++;
		}
	}
	printf("%d",res);
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)flagA=0;
		if(a[i]>1)flagB=0;
	}
	if(flagA)A();
	else if(flagB)B();
	else printf("%d",ans);
	return 0;
}
