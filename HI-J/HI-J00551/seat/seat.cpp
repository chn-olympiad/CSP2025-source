#include<bits/stdc++.h>
using namespace std;
int n,m,mem,c,r;
int v[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%d",&v[1]);
	mem=v[1];
	for(int i=2;i<=n*m;i++){
		scanf("%d",&v[i]);
	}
	sort(v+1,v+n*m+1);
//	for(int i=n*m;i>=1;i--)printf("**%d  ",v[i]);
	for(int i=n*m,k=1;i>=1;i--){
		if(v[i]==mem){
//			printf("*%d  ",k);
			if(k%n==0){
				c=k/n;
			}
			else{
				c=(k/n)+1;
			}
			if(c%2==0){
				r=n-((k-1)%n);
			}
			else if(c%2==1&&k%n==0){
				r=n;
			}
			else{
				r=k%n;
			}
			break;
		}
		k++;
	}
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
