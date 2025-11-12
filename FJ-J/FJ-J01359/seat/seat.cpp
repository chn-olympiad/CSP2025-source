#include<bits/stdc++.h>
using namespace std;
int k;
int a[11100];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+len+1,cmp);
	int h;
	for(int i=1;i<=len;i++){
		if(a[i]==k){
			h=i;
			break;
		}
	}
	int p=ceil(1.00*h/n);
	cout<<p<<" "; 
	if(p%2==1){
		if(h%n==0){
			cout<<n<<endl;
		}
		else cout<<h%n<<endl;
	}
	else {
		if(h%n==0){
			cout<<1<<endl;
		}
	    else cout<<n-(h%n)+1<<endl;
	}
	return 0;
}
