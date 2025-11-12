#include<bits/stdc++.h>
using namespace std;
int b;
bool cmp(int x,int y ){
	return x>y;
}
int a[100000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		 b=a[1];
	}
	
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b&&i<=n){
			cout<<"1"<<' '<<n; 
		}else if(a[i]==b&&a[i]==100){
		cout<<"1"<<' '<<"1";
	}else if(a[i]==b&&i>n){
		cout<<"2"<<n+1;
	}
	
}

	
	return 0;
}
