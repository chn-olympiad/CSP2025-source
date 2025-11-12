#include<bits/stdc++.h>
using namespace std;
int n,sum=0,a[5005],k,maxx=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int f=i+1;f<n;f++){
			if(a[i]>a[f]){
				maxx=a[i];
			}else{
				maxx=a[f];
			}
			for(int j=f+1;j<n;j++){
				if(maxx<a[j]){
					maxx=a[j];
				}
				if(a[i]+a[f]+a[j]>2*maxx){
					sum++;
				}
			}
		}
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
