#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[10005],b,c,d=0,e=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int q=1;q<=j-i+1;q++){
			    b=0;
			    for(int p=q;p<i+q-1;p++){
		    		b+=a[p];
		    	}
	    		if(b>a[j]){
		    		c=j-q+1;
					e=1;
		    	    for(int w=c;w>=c-i+1;w--){
		        		e*=w;
	    			}
					for(int w=1;w<=i;w++){
			    		e/=w;
					}
					d+=e;
					break;
		    	}
		    }
		}
	}
	cout<<d%998244353;
	return 0;
}
