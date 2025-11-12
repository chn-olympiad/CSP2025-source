#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	
	int m,n;
	int a[100];
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int aim=a[1],index;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==aim) index=i;
	}
	int c=1,r=1;
	while(index>0){
		if(index>n){
			index-=n;
			c++;
		}else{
			if(c%2==0) r=n-index+1;
			else r=index;
			index=0;
		}
	}
	cout<<c<<' '<<r;
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
