#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=x*y;i++){
		cin>>a[i];
		}
		int b=a[1];
		int k;
	for(int i=1;i<=x*y;i++){
		for(int j=i;j<=x*y;j++){
			if(a[j]>a[i])
			{
				swap(a[j],a[i]);
			}
		}
		if(b==a[i]){
			k=i;
		}
	}
	int n=k%y,m=k/y;
	if(n==0){
		n=y;
	}
	if(m*y<k){
		m++;
	}
	if(m%2==0){
		cout<<m<<" "<<y-n+1;
	}
	else if(m%2==1){
		cout<<m<<" "<<n;
	}
	return 0;
}
