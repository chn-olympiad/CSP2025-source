#include<bits/stdc++.h>
using namespace std;
int n,k,sum,cnt,a[500005],f[500005],sum1;
bool fl=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
	    cin>>a[i];
	    if(a[i]==0){
	        f[i]=1;
	        sum++;
	    }
	    if(a[i]==1){
	        sum1++;
	    }
	    if(a[i]!=1){
			fl=false;
	    }
	}
	if(fl==true){
		cout<<n/2;
	}else{
		if(k==0){
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1&&f[i]==0&&f[i+1]==0){
					cnt++;
					f[i]=1;
					f[i+1]=1;
				}
		    }
		    cout<<sum+cnt;
		}else{
			cout<<sum1;
	    }
	}
    return 0;
}
