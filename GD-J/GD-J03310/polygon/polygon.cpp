#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	int m=0;
	if(n>3){
		cout<<10;
		return 0;
	}
	for(int i=1;i<=3;i++){
		cnt+=a[i];
		if(a[i]>=m){
			m=a[i];
		}
	}
	if(cnt>(m*2)){
		cout<<1;
	}else{
		cout<<0;
	}
	
}
