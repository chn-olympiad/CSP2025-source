#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,m,a[105],s=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            s++;
        }
	}
	int c=0,r=0;
	c=s/n;
	if(s%n!=0){
        c++;
	}
	if(c%2==0){
        r=n-s%n;
	}
	else if(s%n==0){
        r=n;
	}
    else r=s%n;
	cout<<c<<" "<<r;
	return 0;
}
