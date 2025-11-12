#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool f1=1,f2=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			f1=0;
		}
		if(a[i]>=2){
			f2=0;
		}
	}
	if(n==1){
		if(a[1]==k)printf("1");
		else printf("0");
	}else if(f1){ 
		printf("%d",n/2);
	}else if(f2){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;	
				}				
			}                                       
			for(int i=1;i<=n;){
				if(a[i]==0){
					i++;
				}else{
					if(a[i]==1 && a[i+1]==1){
						ans++;
						i+=2;
					} 
				}
			}
			printf("%d",ans);
		}
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
				if(cnt%2==1){
					cnt=0;
					ans++;
				}
			}
			printf("%d",ans);
		}		
	}
	return 0;
}
