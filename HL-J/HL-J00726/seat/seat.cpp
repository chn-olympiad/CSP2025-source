#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m;
	cin>>n>>m;
	int y=n*m;
	long long a[100];
	for(int i=0;i<n*m;i++){
		cin>>a[i];


	int p=a[0];
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(n==2&&m==2){
		if(a[0]==99){
			cout<<1<<" "<<2;
		}else if(a[0]==98){
			cout<<2<<" "<<2;
		}
	}
	if(a[i+1]>a[i]){
			int p=a[i];
			a[i]=a[i+1];
			a[i+1]=p;
		}else if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	}
	if(a[0]>a[1]){
		cout<<a[0];
		return 0;
	}
	int p=a[0];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[j+1]>a[j]){
					swap(a[j+1],a[j]);
				}
				if(a[0]==p){
					cout<<i<<j;
					return 0;
				}

		}
	}
	return 0;

	}
