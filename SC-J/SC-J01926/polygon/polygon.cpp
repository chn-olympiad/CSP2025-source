#include<bits/stdc++.h>
using namespace std;
int const N=1e8+10;

int n,ans=0;
int a[5005],pre[5005]={};
int f=0; 

bool  cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			f++;
		}
	}
	//sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	if(n==3){
		if(pre[n]>(a[1]*2)){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(f==n){
		cout<<(n*n-3*n+2)/2;
	}else {
		for(int l=1;l+3-1<=n;l++){
			for(int s=3;l+s-1<=n;s++){
				for(int r=l+s-1;r<=n;r++){
					//cout<<a[l]<<"~"<<a[r]<<endl;
					if((pre[r]-pre[l-1])>(a[l]*2)){
						ans++;
					}
				}
			}
			
		}
		cout<<ans;
	}
	return 0;
}