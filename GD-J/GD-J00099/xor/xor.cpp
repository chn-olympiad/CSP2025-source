#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,x=-1,a,tmp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if(a==k){
			ans++;
			x=-1;
		}else if(x==-1){
			x=a;
		}else{
			x=a^x;
		}
		if(x==k){
			ans++;
			x=-1;
		}
	}
	printf("%d",ans);
	return 0;
} 
