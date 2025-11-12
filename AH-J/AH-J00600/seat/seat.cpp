#include<bits/stdc++.h>
using namespace std;
int m,n,s[105],mine,c,r,jl,jll;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
			cin>>s[i];
			if(i==1){
				mine=s[i];
			}
			if(s[i]>mine){
				jl++;
			}
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
		    for(int j=1;j<=n;j++){
			    if(jll==jl)
			    cout<<i<<" "<<j;
			    jll++;
		}
	    }else if(i%2==0){
			for(int j=n;j>=1;j--){
				if(jll==jl)
			    cout<<i<<" "<<j;
			    jll++;
			}
			}
	}
	return 0;
}
