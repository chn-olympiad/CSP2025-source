#include<bits/stdc++.h>
using namespace std;
int a[15],stu[11][11],r,r1,x,c;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	r1=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m*n;i++){
//		cout<<a[i]<<" "<<i<<" ";
		if(a[i]==r1){
			x=i;
			break;
		}
	}
//	cout<<r1<<" "; 
	if(x%n==0){
		r=x/n;
		if(r%2==0){//列数为偶 
			c=1;
		}
		else{//列数为奇 ,一整列最后 
			c=n; 
		}
	}
	else{
		r=x/n+1;
		if(r%2==0){
			c=n-x%n+1;
		}
		else{
			c=x%n;
		}
	}
	printf("%d %d",r,c);
	return 0;
} 
