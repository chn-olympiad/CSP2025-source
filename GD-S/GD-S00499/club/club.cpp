#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int a[1000001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t,n,b,d,ans,c;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		b=n/2;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>d>>c;	
	    }
	    sort(a+1,a+n+1);
        for(int h=n;h>b;h--){
        	ans+=a[h];
		}
		cout<<ans;
		ans=0;
		     
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
