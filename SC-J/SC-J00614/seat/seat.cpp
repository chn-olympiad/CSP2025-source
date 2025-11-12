#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int bj;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int w;
			cin>>w;
			b[w]++;
			if(i==1&&j==1){
				bj=w;	
			}
		}
	}
	int num=0;
	for(int i=100;i>=bj;i--){
		if(b[i]==1){
			num++;
		}
	}
	int c,r;
	if(num%n>0){
		c=num/n+1;
	}else{
		c=num/n;
	}
	if(((num/n)%2)==0&&num%n==0){
		r=1;
	}else if(num%n==0){
		r=n;
	}else if(((num/n)%2)==0){
		r=num%n;
	}else{
		r=n-(num%n)+1;
	}
	cout<<c<<" "<<r;
	return 0;
} 