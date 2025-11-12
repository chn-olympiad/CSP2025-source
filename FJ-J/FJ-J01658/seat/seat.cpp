#include<bits/stdc++.h>
using namespace std;
int a[100];
int t[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
	int R=a[1];
	int c,r;
	sort(a+1,a+n*m+1);
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
	for(int i=1;i<=n*m;i++){
		t[i]=a[n*m-i+1];
	}
	for(int i=1;i<=n*m;i++)a[i]=t[i];
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
	int Rindex=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			Rindex=i;
		}
	}
	//cout<<Rindex<<" ";
	int t1=Rindex/n;//ษฬ 
	//cout<<t1<<" ";
	int t2=Rindex-t1*n;//ำเสý 
	//cout<<t2<<" ";
	if(t1%2==1&&t2==0){
		c=n;
		r=t1;
		cout<<r<<" "<<c;
		return 0;
	}
	else if(t1%2==0&&t2==0){
		c=1;
		r=t1;
		cout<<r<<" "<<c;
		return 0;
	}
	else{
		if(t1%2==1){
			c=n-t2+1;
			r=t1+1;
			cout<<r<<" "<<c;
		return 0;
		}
		if(t1%2==0){
			c=t2;
			r=t1+1;
			cout<<r<<" "<<c;
			return 0;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
