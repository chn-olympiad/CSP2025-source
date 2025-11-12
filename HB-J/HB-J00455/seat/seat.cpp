#include<bits/stdc++.h>
using namespace std;
int n,m;
int b;
int me;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>me;
	for(int i=1;i<n*m;i++){
		int x;
		cin>>x;
		if(x>me)
		b++;
	}
	int l=b/n+1;
	int h=b%n;
	if(l%2==1){
		h=b%n+1;
	}else{
		h=n-b%n;
	}
	cout<<l<<" "<<h;
    return 0;
}
