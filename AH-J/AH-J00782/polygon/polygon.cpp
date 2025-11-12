#include<bits/stdc++.h>
using namespace std;
int n,a[10000],p,h,maxn=INT_MIN,x;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		x+=a[i];
	}
	if(maxn==1){
		cout<<n-2;
		return 0;
	}
	if(n==3){
		if(x>maxn*2){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}
	if(n<3){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			maxn=INT_MIN;
			p=0;
			for(int k=i;k<=j;k++){
				maxn=max(maxn,a[k]);
				p+=a[k];
			}
			if(p>maxn*2){
				h++;
			}
		}
	}
	cout<<h;
	return 0;
}
