#include<bits/stdc++.h>
using namespace std;
int t,n,a[100000][3],b=0,c=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int k=1;k<=t;k++){
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=3;j++){
			    cin>>a[i][j];
		    }
	    }
	}
	for(int k=1;k<=t;k++){
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=3;j++){
			    if(c<a[i][j]){
				    c=a[i][j];
			    }
		    }
		    b=b+c;
	    }
	}
	cout<<b;
	return 0;
}
