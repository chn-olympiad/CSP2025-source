#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int h=n*m;
	int a[h];
	int num=0;
	for(int i=1;i<=h;i++){
		cin>>a[i];
		if(i==1){
		   num=a[i];	
		}
	}
	for(int i=1;i<=h;i++){
		int t=0;
		for(int j=i+1;j<=h;j++){
			if(a[i]<a[j]){
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	int c=1,r=1;
	for(int i=1;i<=h;i++){
		if(r>m){
			c++;
			r=1;
		}
		if(a[i]==num){
			cout<<c<<" "<<r;
		}
		r++;
	}
}
