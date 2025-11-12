#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,tmp;// nrÐÐ mcÁÐ 
int s[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i]);
	}
	tmp=s[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(s[i]<s[j]) swap(s[i],s[j]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(s[i]!=tmp) continue;
		c=ceil(i*1.0/n);
		if(c%2)  r=i%(2*n);
		else if(!(i%n)) r=1;
		else r=n+1-i%n;
		printf("%d %d",c,r);
		return 0; 
	}
}
