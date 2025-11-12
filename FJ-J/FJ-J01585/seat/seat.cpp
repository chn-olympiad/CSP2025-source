#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int p[101];
int n,m,mo=1,x,a=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>p[1];
	for(int i=2;i<=n*m;i++){
		cin>>p[i];
		if(p[i]>p[1]){
			a++;
		}
	}
	while(a>n){
		a-=n;
		y++;
		mo++;
	}
	if(mo%2==1){
		cout<<y<<" "<<a;
	}else{
		cout<<y<<" "<<n-a+1;
	}
} 
