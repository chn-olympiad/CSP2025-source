#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[20][20],b[110],n,m,r,i=1,j=1,s=1;
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&b[i]);
	}
	r=b[1];
	sort(b+1,n*m+b+1,cmp);
	if(r>b[1]){
		printf("%d %d",1,1);
		return 0;
	}
	if(r<b[n*m-1]){
		printf("%d %d",n,m);
		return 0;
	}
	for(int k=1;k<=m;k++){
		if(k%2==1){
			while(i<=n){
				a[i][j]=b[s];
				i+=1;s+=1;
			}
			j+=1;i=n;	
		}
		else{
			while(i>=1){
				a[i][j]=b[s];
				i-=1;s+=1;
			}
			j+=1;i=1;					
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==r){
				printf("%d %d",j,i);
				return 0;
			} 
		}
	}
} 
