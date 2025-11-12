#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++){
		if(a[i]==x){
			if(n==1){
				c=i;
				r=1;
				break;
			}
			if(m==1){
				c=1;
				r=i;
				break;
			}
			c=(i+1)/n;
			if(c%2==0){
				r=c*n-i+1;
				if(r==0){
					r=1;
					c+=1;
				}	
			}else{
				r=i-(c-1)*n;
			}
			break;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
