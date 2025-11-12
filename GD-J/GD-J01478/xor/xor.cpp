#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int f=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)f++;
	}
	if(k==1){
		int ans=0;
		int i=1;
		while(i<=n){
			if(a[i]==0){
				if(a[i+1]==1){
					ans++;i+=2;
				}
				else i++;
			}
			else if(a[i]==1){
				if(a[i+1]==0){
					ans++;i+=2;
				}
				else{
					ans++;i++;
				}			
			}
		}
		printf("%d",ans);
	}
	else{
		if(f==0&&n==2)printf("1");
		else if(f==0&&n==1)printf("0");
		else if(f==0&&n>2)printf("%d",n/2);
		else if(f>0){
			int ans=f;
			int i=2;
			while(i<=n){
				if(a[i]==1&&a[i-1]==1){
					ans++;
					i+=2;
				}
				else i++;
			}
			printf("%d",ans);
		}
	}
	return 0;
}
