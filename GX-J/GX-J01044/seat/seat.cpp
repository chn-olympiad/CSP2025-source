#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	int t[101];
	for(int i=0;i<101;i++){
        t[i]=0;

	}
		int b;
		cin>>b;
		t[b]++;
	for(int i=1;i<m*n;i++){
        cin>>a;
        t[a]++;
	}

	int c=0;
	for(int i=100;i>b;i--){
		c+=t[i];
	}
	int d=c;
	for(int i=1;;i++){
		if(d<n){
			cout<<i<<" ";
		//	cout<<"d="<<d;
			break;
		}
		//cout<<"d="<<d;
		d-=n;
	}
	if((c+1)/n%2==0){
		cout<<1;
		return 0;
	}else{
        cout<<n;
        return 0;
	}
	if((c+1)/n%2==0){
		cout<<n-c%n;
		return 0;
	}else{
        cout<<c%n;
        return 0;
	}
	
    return 0;
}
