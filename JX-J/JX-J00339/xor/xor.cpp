#include<bits/stdc++.h>
using namespace std;
int ans=0,k,n,t[1000005];
bool s[1000005];
bool qu(int j){
	if(s[j]==1){
		return 0;
	}
	return 1;
}
void yihuo(int a,int b){
		int h=a;
		for(int i=a+1;i<=b;i++){
			h=h^t[i];
		}
		if(h==k){
			ans++;
		}
		for(int i=b+1;i<=n;i++){
			if(qu(i)){
			s[i]=1;
			yihuo(b+1,i);
			s[i]=0;
		 }else continue;
		}
		if(b==n){
			return;
		}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
	}
	yihuo(1,1);
	printf("%d",ans);
	return 0;
}
