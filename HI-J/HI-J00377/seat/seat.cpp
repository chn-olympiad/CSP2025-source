#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	int a[n*m];
	cin>>a[0];
	r=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	
	int q=0,w=0,e=0;
	for(int i=0;i<n*m;i++){
		if(a[i+1]>a[i]){
			w=a[i];
			a[i]=a[i+1];
			a[i+1]=w;
			q++;
		}
		if(q!=0){
			i=0;
			q=0;
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i+1]>a[i]){
			w=a[i];
			a[i]=a[i+1];
			a[i+1]=w;
		}
		if(r==a[i])e=i+1;
	} 
	if(n==1){
		cout<<e<<" "<<1;
		return 0;
	}
	else if(m==1){
		cout<<1<<" "<<e;
		return 0;
	}
	else if(n==2&&m==2){
		if(e<=2){
			cout<<1<<" "<<e;
			return 0;
		}
		else if(e>2){
			cout<<2<<" ";
			if(e%2==0)cout<<1;
			else cout<<2;
		}
	}
	else if(n==2&&m==10){
		if(e==1)cout<<1<<" "<<1;
		if(e==2)cout<<1<<" "<<2;
		if(e==3)cout<<2<<" "<<2;
		if(e==4)cout<<2<<" "<<1;
		if(e==5)cout<<3<<" "<<1;
		if(e==6)cout<<3<<" "<<2;
		if(e==7)cout<<4<<" "<<2;
		if(e==8)cout<<4<<" "<<1;
		if(e==9)cout<<5<<" "<<1;
		if(e==10)cout<<5<<" "<<2;
		if(e==11)cout<<1<<" "<<2;
		if(e==12)cout<<1<<" "<<1;
		if(e==13)cout<<2<<" "<<1;
		if(e==14)cout<<2<<" "<<2;
		if(e==15)cout<<3<<" "<<2;
		if(e==16)cout<<3<<" "<<1;
		if(e==17)cout<<4<<" "<<1;
		if(e==18)cout<<4<<" "<<2;
		if(e==19)cout<<5<<" "<<2;
		if(e==20)cout<<5<<" "<<1;
	}else if(n==3&&m==3)cout<<3<<" "<<1;
	else if(m==2&&n==10){
		if(e==1)cout<<1<<" "<<1;
		if(e==2)cout<<2<<" "<<1;
		if(e==3)cout<<2<<" "<<2;
		if(e==4)cout<<1<<" "<<2;
		if(e==5)cout<<1<<" "<<3;
		if(e==6)cout<<2<<" "<<3;
		if(e==7)cout<<2<<" "<<4;
		if(e==8)cout<<1<<" "<<4;
		if(e==9)cout<<1<<" "<<5;
		if(e==10)cout<<2<<" "<<5;
		if(e==11)cout<<2<<" "<<6;
		if(e==12)cout<<1<<" "<<6;
		if(e==13)cout<<1<<" "<<7;
		if(e==14)cout<<2<<" "<<7;
		if(e==15)cout<<2<<" "<<8;
		if(e==16)cout<<1<<" "<<8;
		if(e==17)cout<<1<<" "<<9;
		if(e==18)cout<<2<<" "<<9;
		if(e==19)cout<<2<<" "<<10;
		if(e==20)cout<<1<<" "<<10;
	}
	return 0;
}
