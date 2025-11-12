#include<bits/stdc++.h>
using namespace std;
int a1i=1;
int h;
int main(){
    ios::sync_with_stdio(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n;
	int m;
	int a1;
	cin>>n>>m>>a1;
	for(int i=1;i<n*m;i++){
		int b=0;
		cin>>b;
		if(b>a1){
			a1i++;
		}
	}	
	int l=ceil(1.0*a1i/n);
	//cout<<a1i;
	if(l&1){
		h=a1i-n*(l-1);
	}
	else{
		h=n-a1i+n*(l-1)+1;
	}
	cout<<l<<" "<<h;
    return 0;
}
