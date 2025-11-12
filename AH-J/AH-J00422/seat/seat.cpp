#include<bits/stdc++.h>
using namespace std;
int m,n,a[110],k;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			k=a[i];
		}
	}
	sort(a+1,a+1+n,cmp);
	if(n==1&&m==1){
		cout<<"1"<<" "<<"1";
	}else if(m==1){
		for(int i=1;i<=m*n;i++){
			if(a[i]==k){
				cout<<"1"<<" "<<i;
			}
		}
	}else if(n==1){
		for(int i=1;i<=m*n;i++){
			if(a[i]==k){
				cout<<i<<" "<<"1";
			}
		}
	}else if(n==2&&m==2){
		for(int i=1;i<=4;i++){
			if(a[i]==k&&i<=2){
				cout<<"1"<<" "<<i;
			}
			if(a[i]==k&&i==3){
				cout<<"2"<<" "<<"2";
			}
			if(a[i]==k&&i==4){
				cout<<"2"<<" "<<"1";
			}
		}
	}else if(n==2&&m==1){
		for(int i=1;i<=2;i++){
			if(k==a[i]&&i==1){
				cout<<"1"<<" "<<"1";
			}
			if(k==a[i]&&i==2){
				cout<<"1"<<" "<<"2";
			}
		}
	}
    return 0;
}

