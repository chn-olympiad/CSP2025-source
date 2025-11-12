#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	int g=0;
	int a1;
	int a[100];
	int k=0;
	cin>>n>>m;
	int count=n*m;
	for(int i=1;i<=count;i++){
		cin>>a[i];
	}
	a1=a[1];
	for(int i=1;i<=count;i++){
		for(int j=1;j<=count;j++){
			if(a[j]<a[j+1]&&j<count){
			swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=1;i<=count;i++){
		if(a[i]==a1){
			k=i;
			break;
		}
	} 
	if(k%n==0){
		c=k/n;
	}else{
		c=k/n;
		c++;
	}
	if(c%2==1){
		g=1;
	}else{
		g=2;
	};
	if(g=1){
		if(k%n==0){
			r=n;
			r--;
		}else{
			r=k%n;
			r--;
		}
	}else if(g==2){
		if(k%n==0){
			r=1;
		}else{
			r=k%n;
			r=n-r;
		}
	}
	cout<<c<<" "<<r+1<<endl;
	return 0;
}
