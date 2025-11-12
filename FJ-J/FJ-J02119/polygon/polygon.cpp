#include<bits/stdc++.h>
using namespace std;
int n;
int a[1001010];
int cmp(int x,int y){
	return x>y;
}
long long z_h=0;
int s=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z_h+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(0<(a[2]+a[3])-a[1]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else if(n==4){
		if(a[1]<a[2]+a[3]+a[4]){
			s++;
		}if(a[1]<a[2]+a[3]){
			s++;
		}if(a[1]<a[2]+a[4]){
			s++;
		}if(a[1]<a[3]+a[4]){
			s++;
		}if(a[2]<a[3]+a[4]){
			s++;
		}
	}else if(n==5){
		if(a[1]<a[2]+a[3]+a[4]+a[5]){
			s++;	
		}if(a[1]<a[2]+a[3]+a[4]){
			s++;
		}if(a[1]<a[2]+a[3]+a[5]){
			s++;
		}if(a[1]<a[5]+a[3]+a[4]){
			s++;
		}if(a[1]<a[2]+a[5]+a[4]){
			s++;
		}if(a[2]<a[5]+a[3]+a[4]){
			s++;
		}if(a[1]<a[2]+a[3]){
			s++;
		}if(a[1]<a[2]+a[4]){
			s++;
		}if(a[1]<a[3]+a[4]){
			s++;
		}if(a[2]<a[3]+a[4]){
			s++;
		}//
		if(a[1]<a[2]+a[5]){
			s++;
		}if(a[1]<a[3]+a[5]){
			s++;
		}if(a[1]<a[5]+a[4]){
			s++;
		}if(a[2]<a[3]+a[5]){
			s++;
		}if(a[2]<a[5]+a[4]){
			s++;
		}if(a[3]<a[4]+a[5]){
			s++;
		}
	}else{
		cout<<0;
	}
	cout<<s;
	
	return 0;
}

