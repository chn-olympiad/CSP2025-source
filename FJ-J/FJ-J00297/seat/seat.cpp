#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[105][105],b[100005],o;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	    cin>>k;
	    b[i]=k;
	    o=b[1];
	}
	sort(b+1,b+n*m+1);
	int l=n*m;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[j][i]=b[l];
			    l--;
			    if(a[j][i]==o){
		    		cout<<i<<' '<<j;
		    	}
			}
		}else{
			for(int j=m;j>=1;j--){
				a[j][i]=b[l];
			    l--;
			    if(a[j][i]==o){
		    		cout<<i<<' '<<j;
		    	}
			}
		}
		
	}
	return 0;
}
