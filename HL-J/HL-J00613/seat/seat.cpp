#include<bits/stdc++.h>
using namespace std;
int s[110],a[11][11];
int cnt,n,m,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m*n;i++){
		cin>>s[i];
	}
	x=s[0];
	for(int i=0;i<m*n;i++){
		for(int j=0;j<m*n;j++){
			if(s[j]<s[j+1]){
				cnt=s[j];
				s[j]=s[j+1];
				s[j+1]=cnt;
			}
		}
	}
	int y=0;
	for(int i=0;i<m;i++){
		if(i%2==0){
		    for(int j=0;j<n;j++){
			    a[i][j]=s[y];
			    y++;
			}
	    }
	    if(i%2!=0){
		    for(int j=n;j>0;j--){
			    a[i][j]=s[y];
			    y++;
			}
	    }
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		    if(a[i][j]==x){
		    	i+=1,j+=1;
		    	cout<<i<<' '<<j;
		    	return 0;
			}
	    }
	}
}
