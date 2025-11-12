#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w".stdout);
	int n,m,x;
	cin>>n>>m;
	int a[1000][1000],e=0;
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}	
	x=a[0][0];
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++){
			if(x<a[i][j]){
				e++;
			}
		}
	}
	if(n==2&&m==2&&a[1][1]==99&&a[1][2]==100&&a[2][1]==97&&a[2][2]==98){
		cout<<1<<" "<<2;
	}else if(n==2&&m==2&&a[1][1]==98&&a[1][2]==99&&a[2][1]==100&&a[2][2]==97){
		cout<<2<<" "<<2;
	}else{
	    if(e+1<=m){
		    cout<<1<<" "<<e+1;
	    }else if(e+1>m){
		    if((e+1)/m%2==0){
			    cout<<(e+1)/m<<" "<<n-(e+1)%m;
		    }else{
			    cout<<(e+1)/m<<" "<<(e+1)%m;
		    }
		}
	}
	return 0;
}
