#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(k==0){
		printf("1");
		//return 0;
	}
	if(k==1){
		bool f=false;
		int temp=0,ans=0,x,y;
		if(a[1]==1){
			x=1;
			y=0;
		}
		if(a[1]==0){
			x=0;
			y=1;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==x){
				f=true;
				temp++;
			}
			if(a[i]==y&&f==true){
				ans=max(ans,temp);
				temp=0;
				f=false;
			}
		}
		printf("%d",ans);
		return 0;
	}
	return 0;
}

