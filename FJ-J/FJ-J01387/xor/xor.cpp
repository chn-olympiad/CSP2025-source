#include<bits/stdc++.h> 
using namespace std;
long long n,a[100005],num,k,v[100005];
int ttt(int x,int y){
	int t,tx[114514],ty[114514],tz[114514],z;
	for(int i=0;i<20;i++){
		tx[i]=x%2;
		ty[i]=y%2;
		z++;
	}
	for(int i=z;i>=0;i--){
		if(tx[i]==ty[i]&&tx[i]==1){
			tz[i]=0;
		}else if(tx[i]!=ty[i]){
			tz[i]=1;
		}else{
			tz[i]=0;
		}
	}
	for(int i=z-1;i>=0;i--){
		int j=1;
		t=tz[z]+pow(2,j)*tz[i];
		j++;
	}
	return t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i]; 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(v[i]==0&&v[j]==0){
				if(ttt(i,j)==k){
					num++;
					v[i]=1,v[j]=1;
				}
			} 
		}
	}
	cout<<num;
	return 0;
}
