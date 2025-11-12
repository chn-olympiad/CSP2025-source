#include <bits/stdc++.h>
using namespace std;
int n,li[5005];
int p(int l[5005],int m){
	int mx=0,all=0;
	for(int i=0;i<m;i++){
		mx=max(mx,l[i]);
		all+=l[i];
	}
	if(all>max)return 1;
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>li[i];
	}
	for(int i=1;i<=n;i++){//长度 
		for(int r=0;r<i;r++){//r的长度 
			for(int j=r+1)//l的开头 
		}
	}
	return 0;
}
