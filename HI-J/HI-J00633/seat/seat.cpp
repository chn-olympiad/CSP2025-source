#include<bits/stdc++.h> 
using namespace std;
int a[105],k[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i];
		}
	}
	int s=a[1];
	sort(a+1,a+1+n*m);
	int x=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
		    for(int j=1;j<=n;j++){
			    k[j][i]=a[x];
			    x--;
			    if(k[j][i]==s){
			    	c=j;
			    	r=i;
				}
		    }
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				k[j][i]=a[x];
				x--;
				if(k[j][i]==s){
					c=j;
					r=i;
				}
			}
		}
	}
	cout<<r<<" "<<c;
	return 0;
}
