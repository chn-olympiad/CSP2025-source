#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int t,a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	int ans=0;
    	int n;
    	cin>>n;
        for(int i=1;i<=n;i++)
    		cin>>a[i]>>b[i]>>c[i];
	    sort(a+1,a+1+n);
		for(int i=n;i>=n/2;i--)ans+=a[i];
		cout<<ans<<endl;
	}
}
