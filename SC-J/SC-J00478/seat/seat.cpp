#include<bits/stdc++.h>
using namespace std;
#define ll long long
int f[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,x=1;
	cin>>n>>m;
	int t=m*n;
	for(int i=1;i<=t;i++){
		cin>>f[i];
		if(i!=1){
			if(f[i]>f[1]){
				x++;
			}
		}		
	}
	int a=x/n;
	int b=x%n;
	if(b!=0){
		a++;
		if(a%2==0){
			cout<<a<<" "<<n-b+1;
		}else{
			cout<<a<<" "<<b;
		}
	}else{
		if(a%2==0){
			cout<<a<<" "<<1;
		}else{
			cout<<a<<" "<<n;
		}
	}	
	return 0;
}
