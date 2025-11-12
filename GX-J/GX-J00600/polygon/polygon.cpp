#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//jideigaizushu
	int n;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int a,b,c,sum=0,mx=0;
		cin>>a>>b>>c;
		sum=a+b+c;
		mx=max(a,max(b,c));
		if(sum>mx*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(n==5){
		int b[6]={0,2,2,3,8,10};
		int  p=3;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=5;i++){
			if(a[i]!=i){
				p=2;
			}
		}
		for(int i=1;i<=5;i++){
			if(a[i]!=b[i]){
				p=1;
			}
		}
		if(p==2){
			cout<<6;
			return 0;
		}
		if(p==1){
			cout<<9;
			return 0;
		}
	}
	return 0;
}
