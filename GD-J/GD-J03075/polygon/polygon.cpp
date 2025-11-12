#include<bits/stdc++.h>

using namespace std;

int const maxx=5000+10;

int n,a[maxx],ans;

int bin(int x){
	int g=0,c[maxx],now=1;
	
	while(x){
		if(x%2==1){
			x=x-1;
			c[now]=1;
			x=x/2;
		}
		else if(x%2==0){
			x=x/2;
			c[now]=0;
		}
		now++;
	}
	
	for(int i=1;i<now;i++){
		int cnt=i-1;
		g=g+c[i]*pow(10,cnt);
	}
	return g;
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=0;
	for(;i<pow(2,n+1)-1;i++){
		int cnt1=bin(i);
		int kk=-1,sum;
		for(int j=1;j<=n;j++){
			int cnt2=cnt1%10;
			if(cnt2==1){
				sum+=a[j];
				kk=max(kk,a[j]);
			}
			cnt1=cnt1/10;
		}
		if(sum>(2*kk)){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}

