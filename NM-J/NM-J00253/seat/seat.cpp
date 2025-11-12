#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int b[105];
int wz=1;
int r;
int seat(int c){
	int cs,ys;
	if(c<=n){
		cout<<1<<" "<<c;
		return 0;
	}
	ys=c%n;
	if(ys==0){
		cs=c/n;
		if(cs%2==0){
			cout<<cs<<" "<<1;
			return 0;
		}cout<<cs<<" "<<n;
		return 0;
	}else{
		cs=c/n+1;
		if(cs%2==0){
			cout<<cs<<" "<<n-ys+1;
			return 0;
		}cout<<cs<<" "<<ys;
		return 0;
	}
	cout<<cs<<endl;
	if(cs%2==0){
		cout<<cs<<" "<<n-ys+1;
		return 0;
	}
	cout<<cs<<" "<<ys;
	return 0;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    for(int i=0;i<m*n-1;i++){
    	cin>>b[i];
    	if(r<b[i]){
    		wz++;
		}
	}
	seat(wz);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
