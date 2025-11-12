#include<bits/stdc++.h>
using namespace std;
const int N=105;
int mp[N][N];
int n,m,R,rnum;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freoprn("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			rnum=i;
			break;
		}
	}
	int r,c,modr=rnum%n,rmod=rnum/n;
	if(rmod%2==0 && modr!=0){
		r=modr;
		c=rmod+1; 
	}else if(rmod%2==0 && modr==0){
		r=1;
		c=rmod;
	}else if(rmod%2!=0 && modr!=0){
		r=n+1-modr;
		c=rmod+1;
	}else if(rmod%2!=0 && modr==0){
		r=n;
		c=rmod;
	}
	cout<<c<<" "<<r<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
