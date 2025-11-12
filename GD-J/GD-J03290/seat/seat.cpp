#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int y,b,l,k,num=1;
	int r;
	cin>>y>>b;
	int u=y*b;
	int m=1,n=1;
	int a[u];
	cin>>a[1];
	k=a[1];
	for(int i=2;i<=u;i++){
		cin>>a[i];
	}	
	for(int i=1;i<=u;i++){
	for(int pp=i+1;pp<=u;pp++){
		if(a[pp]>a[i]){
			l=a[pp];
			a[pp]=a[i];
			a[i]=l;
		}
	}
} 	
for(int i=1;i<=u;i++){
	if(a[i]==k){
		r=i;
	}
}
	for(int i=1;i<=b;i++){
			if(num==r){
				cout<<m<<" "<<n;
				return 0;
			}
		for(int ii=1;ii<=y-1;ii++){
			if(i%2!=0){
				n++;
			num++;	
			}
			if(i%2==0){
				n--;
				num++;
			}
			if(num==r){
				cout<<m<<" "<<n;
				return 0;
			}
		}
		m++;
		num++;
	}



	return 0;
}
