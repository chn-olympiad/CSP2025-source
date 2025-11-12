#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m;
int zs=0;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cj=0;
	int pm=0;
	cin>>n>>m;
	zs=n*m;
	for(int i=1;i<=zs;i++){
		cin>>a[i];
		cj=a[1]; 
	}
	sort(a+1,a+1+zs,cmp);
	for(int i=1;i<=zs;i++){
		if(a[i]==cj){
			pm=i;
		}
	}
	int c=1,r=1;
	if(pm==1){
		c=1,r=1;
		cout<<c<<" "<<r; 
	}else{
		while(pm>c*n)
			c++;
		if(zs%2==0){
			if(pm%m==0)
				r=m;
			else
				r+=pm%c;	
		}else{
			r=pm%n;
		} 
		cout<<c<<" "<<r;
	}
	return 0;
}
