#include<bits/stdc++.h>
using namespace std;
int n,a[5000],maxn=0,am[5000]={0};
int in(int b){
	if(b=0){
		int c[n],d=0; 
		maxn=0;
		for(int i=0;i<n;i++){
			if(am[i]){
				c[d]=a[i];
				d++;
				maxn=max(maxn,a[i]);
			}
		}
		int sh=0;
		for(int i = 0;i<b;i++){
			sh+=c[i];
		}
		if(sh>maxn*2){
			return 1;
		}else{
			return 0;
		}
	}
	int bx=0;
	for(int i=0;i<n;i++){
		if(am[i]) continue;
		am[i]=1;
		bx+=in(b-1);
		am[i]=0;
	}
	return bx;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i]; 
	}
	int y=0;
	for(int i = 3;i<=n;i++){
		y+=in(i);
	}
	cout<<y;
	return 0;
} 
