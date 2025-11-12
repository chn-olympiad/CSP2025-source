#include<bits/stdc++.h>
using namespace std;
long long int a[20][20],s1[500],s[500];
long long int n,m,cnt=1,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
    	cin>>s1[i];
    	if(i==1) r=s1[1];
	}
	sort(s1+1,s1+m*n+1);
	for(int i=m*n;i>=1;i--){
		s[cnt]=s1[i];
		cnt++;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
		    if(i%2==1){
		    	a[i][j]=s[((i-1)*n)+j];
		    }else{
		    	a[i][j]=s[i*n+1-j];
	    	}	
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==r) cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
} 
