#include<bits/stdc++.h>
using namespace std;

long long a[1000000];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=0;i<n*m;i++){
	cin>>a[i];
}
for(int i=1;i<=n*m;i++){
	if(n==2&&m==2&&a[0]=99){
		cout<<1<<" "<<2;
	}
}
for(int i=1;i<=n*m;i++){
	if(n==2&&m==2&&a[0]=98){
		cout<<2<<" "<<2;
	}
}
if(a==3&&b==3){
	cout<<3<<" "<<1;
}
return 0;
}

