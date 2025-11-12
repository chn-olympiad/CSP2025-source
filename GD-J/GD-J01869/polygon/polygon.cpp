#include<bits/stdc++.h>
using namespace std;
int n,a[10000000],sum=0,b[10000000],k;
int ju(){
	int he=0;
	for(int i=0;i<k;i++){
		he+=b[i];
	}
	if(he>2*b[k-1]){
		return 1;
	}else{
		return 0;
	}
} 
void dfs(int x,int y){
	if(x==0){
		if(ju()){
			sum++;		
		}
		return;
	}
	for(int i=y+1;i<=n-(2-(k-x));i++){
		b[k-x]=a[i];
		x--;
		dfs(x,i);		
		x++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);    
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=3;i<=n;i++){
		dfs(i,0);
		k=i; 
	}
	cout<<sum-1;
	return 0;
}
