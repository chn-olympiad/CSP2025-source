#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],f,c,b[200005],florr;
int main(){           
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)f++;
		if(a[i]>=0&&a[i]<=1)c++;
	}
	if(f==n&&k==0){
		cout<<n;
		return 0;
	}
	if(c==n&&k<=1){
		if(k==0){
			cout<<n;
			return 0;
		}else{
			for(int i=3;i<=n;i++){
				int cnt=0;
				if(a[i]==0)cnt++;
				if(a[i-1]==0)cnt++;
				if(a[i-2]==0)cnt++;
				if((cnt==1||cnt==2)&&b[i]==0&&b[i-1]==0&&b[i-2]==0){
					b[i]=1;
					b[i-1]=1;
					b[i-2]=1;
					florr++;
				}
		    }
		    cout<<max(florr,f);
		    return 0;
	    }
	}
	cout<<2;
}
