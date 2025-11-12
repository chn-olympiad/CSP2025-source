#include<iostream>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<cmath>
using namespace std;
int out=0;
const int mod=998244353;
int n,a[5005],ans=0,he[5005][5005]={0},da[5005][5005]={0};
void read(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	return;
}
void hedfs(int left,int right){
	if(left<right){
		int l=left,mid=(left+right)/2,r=right;
		if(he[l][mid]==0 or he[mid+1][r]==0){
			hedfs(left,mid);
			hedfs(mid+1,right);
		}
		he[left][right]=he[l][mid]+he[mid+1][r];
	}
	return;
}
void dadfs(int left,int right){
	if(left<right){
		int l=left,mid=(left+right)/2,r=right;
		if(da[l][mid]==0 or da[mid+1][r]==0){
			dadfs(left,mid);
			dadfs(mid+1,right);	
		}
		da[left][right]=max(da[l][mid],da[mid+1][r]);
	}
	return;
}
void hebuild(){
	for(int i=1;i<=n;i++){
		he[i][i]=i;
	}
	hedfs(1,n);
	he[1][n]=he[1][(1+n)/2]+he[(1+n)/2+1][n];
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cout<<i<<' '<<j<<' '<<he[i][j]<<endl;
		}
	}
	cout<<endl;*/
}
void dabuild(){
	for(int i=1;i<=n;i++){
		da[i][i]=i;
	}
	dadfs(1,n);
	da[1][n]=max(da[1][(1+n)/2],da[(1+n)/2+1][n]);
	/*cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cout<<i<<' '<<j<<' '<<da[i][j]<<endl;
		}
	}
	cout<<endl;*/
}
void findhedfs(int left,int right,int l,int r,int &ans){
	if(l<=r){
		if(l==r and left<=l and r<=right){
			ans+=he[l][r];
			return;
		}
		if(l==r)return;
		int mid=(l+r)/2;
		if(left<=l and r<=right){
			ans+=he[l][r];

			return;
		}
		if(l<=left){
			findhedfs(left,right,mid+1,r,ans);
		}
		if(r>=right){
			findhedfs(left,right,l,mid,ans);
		}
	}
	return;
}
void finddadfs(int left,int right,int l,int r,int &ans){
	if(l<=r){
		if(l==r and left<=l and r<=right){
			ans=max(da[l][r],ans);
			return;
		}
		if(l==r)return;
		int mid=(l+r)/2;
		if(left<=l and r<=right){
			ans=max(da[l][r],ans);
			return;
		}
		if(l<=left){
			finddadfs(left,right,mid+1,r,ans);
		}
		if(r>=right){
			finddadfs(left,right,l,mid,ans);
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read();
	hebuild();
	dabuild();
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			int q1=0;
			findhedfs(i,j,1,n,q1);
			int q2=-1;
			finddadfs(i,j,1,n,q2);
			if(q1>2*q2){
				out++;
			}
		}
	}
	cout<<out%mod;
	/*for(int l=1;l<=n;l++){
		for(int r=l+2;r<=n;r++){
			
		}
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
