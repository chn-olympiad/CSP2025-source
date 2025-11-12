#include<iostream>
using namespace std;
int n,m;
int R;
int a[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	if(n==1&&m==1){
		cin>>R;
		cout<<1<<" "<<1;
	}else if(n==2&&m==2){
		for(int i=1;i<=n*m;i++){
			cin>>a[i];
		}
		R=a[1];
		for(int i=1;i<=n*m;i++){
			for(int j=1;j<=n*m-i;j++){
				if(a[j]<a[j+1]){
					swap(a[j],a[j+1]);
				}
			}
		}
		int num=0;
		for(int i=1;i<=n*m;i++){
			if(a[i]==R){
				num=i;
			}
		}
			if(n==2&&m==2){
			if(num==1){
				cout<<1<<" "<<1;
			}else if(num==2){
				cout<<1<<" "<<2;
			}else if(num==3){
				cout<<2<<" "<<2;
			}else{
				cout<<2<<" "<<1;
			}
		}
	}else if(n==1&&m<=10){
		for(int i=1;i<=n*m;i++){
			cin>>a[i];
		}
		R=a[1];
		for(int i=1;i<=n*m;i++){
			for(int j=1;j<=n*m-i;j++){
				if(a[j]<a[j+1]){
					swap(a[j],a[j+1]);
				}
			}
		}
		for(int i=1;i<=n*m;i++){
			if(a[i]==R){
				cout<<i<<" "<<1;
			}
		}
	}else if(n<=10&&m==1){
		for(int i=1;i<=n*m;i++){
			cin>>a[i];
		}
		R=a[1];
		for(int i=1;i<=n*m;i++){
			for(int j=1;j<=n*m-i;j++){
				if(a[j]<a[j+1]){
					swap(a[j],a[j+1]);
				}
			}
		}
		for(int i=1;i<=n*m;i++){
			if(a[i]==R){
				cout<<1<<" "<<i;
			}
		}
	}else if(n==2&&m<=10){
		for(int i=1;i<=n*m;i++){
			cin>>a[i];
		}
		R=a[1];
		for(int i=1;i<=n*m;i++){
			for(int j=1;j<=n*m-i;j++){
				if(a[j]<a[j+1]){
					swap(a[j],a[j+1]);
				}
			}
		}
		int flag=0;
		for(int i=1;i<=n*m;i++){
			if(a[i]==R){
				flag=i;
			}
		}
		if(flag%4!=0){
			cout<<((flag/4)+1)*2;
			if(flag%4==1){
				cout<<" "<<1;
			}else if(flag%4==2){
				cout<<" "<<2;
			}else if(flag%4==3){
				cout<<" "<<2;
			}
		}else{
			cout<<(flag/4)*2<<" "<<1;
		}
	}
	return 0;
}
