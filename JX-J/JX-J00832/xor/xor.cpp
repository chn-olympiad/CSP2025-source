#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,k,a[800000],ans;
int xxor(int x,int y){
	int aa[111]={0},bb[111]={0},ll=0;
	if(x==0)
	return y;
	if(y==0)
	return x;
	for(int i=13;x>0;i--){
		if(x-pow(2,i)>=0){
		x-=pow(2,i);
		aa[i]+=1;}
	}
	for(int i=13;y>0;i--){
		if(y-pow(2,i)>=0){
		y-=pow(2,i);
		bb[i]+=1;}
	}
	for(int i=0;i<=13;i++){
		if(aa[i]!=bb[i])
		ll+=pow(2,i);}
		return ll;
}
int main(){
	freopen("xor.in","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	freopen("xor.out","w",stdout);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int u=0;
		for(int o=i;o<=j;o++){
			u=xxor(u,a[o]);
		}
		cout<<i<<" "<<j<<" "<<u<<" ";
		if(u==k)
		ans++;
	}
}
cout<<ans;
}
