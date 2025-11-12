#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,k;
int a[500005],ans=0;
int oo(int x,int y){
	int num=a[x];
	for(int i=x+1;i<=y;i++){
		num=int(num^a[i]);
	}
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(oo(l,r)==k) {
				ans++;
				l+=r-l+1;
				if(l>n) break;
			} 
		}
	}
	printf("%d",ans);
	return 0;
} 
