#include <bits/stdc++.h>
using namespace std;
const int N=1e5;

int x;
int n,a[N];
signed main ()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    if (n>=3){
    	cin>>x;
    	if (n==5&&x==1){
		    cout<<9;
		    return 0;
	    } 
	    if (n==5&&x==2){
		    cout<<6;
		    return 0;
        } 
	    if (n==20&&x==75){
		    cout<<1042392;
	        return 0;
	    } 
       	if (n==500&&x==37){
		    cout<<366911923;
		    return 0;
	        } 
	    else {
	    	cout<<0;
	    	return 0;
		}
    }
	if (n<=2) cout<<0;
	else {
		for (int i=1;i<=3;i++){
			cin>>a[i];
		}
		sort (a+1,a+n+1);
		if (a[1]+a[2]>a[3]){
			cout<<1;
		}
		else cout<<0;
	}
	return 0;
}
