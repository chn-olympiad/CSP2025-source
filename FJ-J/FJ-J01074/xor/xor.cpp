#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,k,s,ans,tail,a[N];
int yhh(int x,int y,int numm[]){
	int ansyhh=0;
	for(int i=x;i<=y;i++) ansyhh=ansyhh^numm[i];
	return ansyhh;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(yhh(i,j,a)==k && i>tail){
				ans++;
				tail=j;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}