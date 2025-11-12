#include<bits/stdc++.h>
using namespace std;
int n,k,num[500005],x[500005],ans;
void init(){
	ans=0;
	x[0]=num[0];
	for(int i=0;i<500005;i++){
		x[i]=x[i-1] xor num[i];
	}
	return ;
}
int get_num(int l,int r){
	if(l==r){
		return num[l];
	}
	if(l==0){
		return x[r];
	}
	return x[r] xor x[l-1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	init();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(get_num(i,j)==k){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
