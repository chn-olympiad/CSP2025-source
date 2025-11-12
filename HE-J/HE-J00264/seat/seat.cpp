#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m,n,c,r;
	int sum=0;
	int a[10010];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x)  sum=n*m+1-i;
	}
	int b=sum;
	int num=sum/(2*n)+1;
	sum-=((num-1)*2*n);
	if(sum<=n){
		c=num*2-1;
		r=(b-1)%n+1;
		cout<<c<<" "<<r;
		return 0;
	}
	else{
		c=num*2;
		r=2*n-sum+1;
		cout<<c<<" "<<r;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
