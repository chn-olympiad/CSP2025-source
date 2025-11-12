#include <bits/stdc++.h>
using namespace std;
int n,m,a[505],num=0;
string x;
bool sum[505];
void kl(int y,int c,int l){
	if(y==n){
		if(c==m){
			num++;
		}
		return;
	}
	for (int i=0;i<n;i++){
		if(sum[i]==0){
			if(x[i]=='1'&&l<a[i]){
				sum[i]=1;
				return kl(y+1,c+1,l);
				sum[i]=0;
			}else{
				sum[i]=1;
				return kl(y+1,c,l+1);
				sum[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>x;	
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	kl(0,0,0);
	cout<<num;
	return 0;
}
