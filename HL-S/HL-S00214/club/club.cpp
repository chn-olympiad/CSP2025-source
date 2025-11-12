#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,a[10000],sum=0,maxx=-1,t;
	cin>>t;
	int bm[2];
	for(int k=0;k<t;k++){
		maxx=-1,sum=0;
		cin>>n;
		for(int i=0;i<n;i++){
		    for(int j=0;j<3;j++){
			    cin>>a[j];
			    if(a[j]>maxx){
				    maxx=a[j];
			    }
		    }
		    sum+=maxx;
	    }
	    cout<<sum;
	}
	return 0;
}