#include<bits/stdc++.h>
using namespace std;
int a[1012],ys=998244353,sum=0,n;
bool b[1012];
void add(int ma,int h,int bm){
	if(h>ma*2){
		sum++;
		sum=sum%ys;
	}
	for(int i=bm+1;i<=n;i++){
		if(b[i]!=1){
			b[i]=1;
			add(max(ma,a[i]),h+a[i],i);
			b[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	add(0,0,0);
	cout<<sum; 
	return 0;
} 
