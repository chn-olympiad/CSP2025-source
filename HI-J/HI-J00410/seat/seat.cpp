#include<bits/stdc++.h>
using namespace std;
int n,m,r,t,a[110],l,h,b[110][110],c=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    a[1]=r;
    for(int i=2;i<=n*m;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
		    if(a[i]<a[j]){
		    	if(a[i]==r){
		    		t=j;
				}
		    	swap(a[i],a[j]);
			}
	    }
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(a[c]==r){
					l=i;
					h=j;
				}
				b[i][j]=a[c];
				c++;
			}	
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[c]==r){
					l=i;
					h=j;
				}
				b[i][j]=a[c];
				c++;
			}
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
