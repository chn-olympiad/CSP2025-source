#include<bits/stdc++.h>
using namespace std;
long long op(int x,int y){
	long long ans=1;
	for(int i=1;i<=x;i++){
		if(y==0) break;
		ans*=i;
		y--;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a=0,maxx=0,sumx=0;
	cin>>n;
	if(n<3){
		cout<<0;
	}else if(n==3){
		while(n--){
			cin>>a;
			sumx+=a;
			maxx=max(maxx,a);
		}
		if(maxx*2<sumx) cout<<1;
		else cout<<0;
	}else if(n>=4){
		long long ans=0;
		for(int i=4;i<=n;i++){
			if(i==n){
				ans+=1;
				break;
			} 
			ans+=op(n,i)/op(i,i);
		}
		cout<<ans;
	}
	return 0;
}