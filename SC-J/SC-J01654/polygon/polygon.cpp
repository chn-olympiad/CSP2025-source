#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(n==2){
		cout<<"0";
		return 0;
	}
	int a[5005];
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	if(flag==0){
		cout<<"0";
		return 0;
	}
	if(n==3){
		int m=max(a[1],max(a[2],a[3]));
		if((a[1]+a[2]+a[3])>(m*2)){
			cout<<"1";
			
		}
		else{
			cout<<"0";
		}
		return 0;
	}
	
	if(n==4){
		sort(a+1,a+5);
		int ans=0;
		for(int b=1;b<=4;b++){
			for(int c=b+1;c<=4;c++){
				for(int d=c+1;d<=4;d++){
					if((a[b]+a[c])>a[d]){
						ans++;
					}
				}
			}
		}
		if((a[1]+a[2]+a[3])>a[4]) ans++;
		cout<<ans;
		return 0;
	}

	
	return 0;
}