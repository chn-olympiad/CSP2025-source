#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[105],c,r,sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x=a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(sum=1;sum<=n*m;sum++){
		if(a[sum]==x)break;
	}
	//sum++;
	if(sum%n==0){
		c=sum/n;
		if(c%2==0)r=1;
		else r=n;
	}
	else{
		c=sum/n+1;
		if(c%2==0){
			r=n-sum%n+1;
		}else{
			r=sum%n;
		}
	}
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
	//cout<<sum<<endl;
	/*for(c=1;c<=m;c++){
		if(c%2==1){
			for(r=1;r<=n;r++){
				if((c-1)*n+r>=sum)break;
			}
			
			if((c-1)*n+r>=sum)break;
		}else{
			for(r=n;r>=1;r--){
				if((c-1)*n+(n-r)>=sum)break;
			}
			
			if((c-1)*n+(n-r)>=sum)break;
		}
	}*/
	cout<<c<<" "<<r;
	return 0;
}
