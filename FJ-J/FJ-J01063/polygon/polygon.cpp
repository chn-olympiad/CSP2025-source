#include<bits/stdc++.h>
using namespace std;
int n,a[5005],num,ans,c[5005],x;
bool cmp(int a,int b){
	return a>b;
}
void Meiju(int r,int i){
	for(;i<=n-r+1;i++){
		c[++x]=a[i];
		num+=a[i];
		if(r>1){
			Meiju(r-1,i+1);
		}else{
			sort(c+1,c+x,cmp);
			if(num>2*c[1]){
				ans++;
			}
		}
		c[x--]=0;
		num-=a[i];
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		Meiju(i,1);
	}
	cout<<ans;
	return 0;
}
