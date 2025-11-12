#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m,x,num=0,h,l;
bool cmp(int z,int y){
	return z>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	//for(int i=m,j=1;i>=1;i++,j++) b[j]=i;
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=m*n;i++) cout<<a[i];
	for(int i=1;i<=n*m;i++) if(a[i]==x){num=i;break;}
	if(num%m>0) {h=num/m+1;}
	else {h=num/m;}
	cout<<h<<" ";
	if(h%2==1){
		if(num%n==0) cout<<m;
		else cout<<num%n;
	}	
	else cout<<n*h-num+1;
	//cout<<num;
	return 0;
}

