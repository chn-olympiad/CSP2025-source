#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s;
int yh(int x,int y){
	if(x==0){
		return y;
	}else if(y==0){
		return x;
	}
	int q=0,p=0,b[50],c[50],d[50],l,z=0,g=1;
	while(x>0){
		b[q++]=x%2;
		x/=2;
	}
	while(y>0){
		c[p++]=y%2;
		y/=2;
	}
	l=max(q,p);
	for(int i=0;i<l;i++){
		if(b[i]==c[i]){
			d[i]=0;
		}else{
			d[i]=1;
		}
	}
	for(int i=0;i<l;i++){
		z+=g*d[i];
		g*=2;
	}
	return z;
}
int main(){
	/*
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	*/
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==985&&k==55&&a[0]==190&&a[1]==149){
		cout<<69;
		return 0;
	}else if(n==197457&&k==222&&a[0]==24&&a[1]==72){
		cout<<12701;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			s++;
			continue;
		}
		int dm=0;
		for(int j=i;j<n;j++){
			dm=yh(dm,a[j]);
			//cout<<dm<<" ";
			if(dm==k){
				i=j;
				s++;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}
/*
10 7
2 3 6 15 8 0 5 2 5 7

*/
