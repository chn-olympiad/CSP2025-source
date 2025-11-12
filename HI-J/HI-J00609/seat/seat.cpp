#include<bits/stdc++.h>
using namespace std;
int a[101];
int cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m;
    cin>>r;
    a[0]=r;
    for(int i=1;i<n*m;i++){
    	cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
    	cout<<a[i]<<' ';
	}
	cout<<endl;
	for(int i=0;i<m;i++){
		if(i%2==0){
			cout<<1<<endl;
			for(int j=0;j<n;j++){
				if(a[2*i+j]==r){
					cout<<i+1<<' '<<j+1;
					return 0;
				}
			}
		}else if(i%2!=0){
			cout<<2<<endl;
			int b=0;
			for(int j=n-1;j>=0;j--){
				if(a[2*i+b]==r){
					cout<<i+1<<' '<<j+1;
				    return 0;
				}
				b++;
			}
		}
	}
    return 0;
}

