#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int ans;
int yihuo(int x,int y){//异或 
	return -(~(x&y)); 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int totz=0,toto=0;//记录0的个数 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) toto++; //性质A 
		if(a[i]==0) totz++; //性质B
	}
	if(toto==n&&k==1){//性质A 
		cout<<n;
		return 0;
	}
	if(totz+toto==n){//性质B 
		if(k==1) cout<<toto;
		else if(k==0) cout<<totz; 
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){//起点 
		int tmp=a[i];
		for(int j=i;j<=n;j++){//终点 
			if(a[j]==k){
				ans++;
				i=j;
				continue;
			} 
			tmp=yihuo(tmp,a[j]);
			if(tmp==k){
				ans++;
				i=j;
			}
		}
	}
	cout<<ans;
	return 0;
}