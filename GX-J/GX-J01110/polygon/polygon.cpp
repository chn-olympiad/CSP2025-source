#include<bits/stdc++.h>
using namespace std;
int n,a[5005],c,maxa,s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
int t=1,d=1;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	maxa=max(max(a[0],a[1]),a[2]);
	if(n<3){
		cout<<c;
			return 0;
	}else{
		if(n>3){
			for(int i=1;i<=n;i++){
				t=t*i;	
			}
			for(int i=3;i<=n;i++){
				for(int j=1;j<=i;j++){
					d=d*i;
					}
					s=t/d;
				c=c+s;
			}
		}else{
		if(a[0]+a[1]+a[2]>=maxa*2){
			c++;
			cout<<c;
				return 0;
		}
		}
	}
	cout<<c;
	return 0;
}
