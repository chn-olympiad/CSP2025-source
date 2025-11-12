#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	int n,m,a[103],e=0,d=0;
	int c,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	e=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				d=a[i];
				a[i]=a[j];
				a[j]=d;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==e){
			c=i/n;
			if(i%n!=0){
				c+=1;
			}
			if(c%2==0){
				r=i%n;
				r=n-r+1;
			}
			else if(c%2==1&&i%n==0){
				r=n;
			}
			else{
				r=i%n;
			}
			printf("%d ",c);
			printf("%d",r);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
