#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],b,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>b;
	a[1]=b;
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=n*m+1,mid;
	while(l<r){
		mid=(l+r)/2;
		if(a[mid]==b){
			break;
		}else if(a[mid]>b){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	int x=floor(mid/n);
	if(mid%n!=0){
		x++;
		if(x%2==0){
			y=n-mid%n+1;
		}else{
			y=mid%n;
		}
	}else{
		if(x%2==0){
			y=1;
		}else{
			y=n;
		}
	}
	printf("%d %d",x,y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
