#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;//c,mÁÐ, r,nÐÐ
int a[101],b,x;
int sum;//ÅÅÃû 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x;
		if(i==1)b=x;
		a[x]++;
	}
	for(int i=100;i>b;i--){
		sum+=a[i];
	}
	sum+=1;
//	cout<<sum<<endl;
	if(sum%n==0)c=sum/n;
	else c=sum/n+1;
	if(c%2==1){
		r=sum%n;
		if(r==0)cout<<c<<" "<<n;
		else cout<<c<<" "<<r;
		return 0;
	}else {
		r=n-(sum%n)+1;
		if(r==n+1)cout<<c<<" 1";
		else cout<<c<<" "<<r;
	}
//	cout<<c<<" "<<r;
	return 0;
} 
