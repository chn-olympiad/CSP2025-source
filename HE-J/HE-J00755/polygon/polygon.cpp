#include<bits/stdc++.h>
using namespace std;
int a[6000];
int h[6000];
int u;
void ef(int l,int r,int m){
	if(u==m){
		return;
	}else if(u==m-1){
		
	}else{
		u++;
		for(int i=l;i<n;i++){
			ef(l++,r+a[l],m);
		}
		u--;
	}
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	for(int m=3;m<=n;m++){
		int b=0;
		b=a[m];
		ef()
		
	}
    return 0;
}
