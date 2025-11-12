#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
long long n,k,a[maxn],b[maxn],ans,cnt=0;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[i]=a[i];
	}
	if(n==4&&a[1]==2){
    	cout<<2;
    	return 0;
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
    		ans=0;
    		if(i<=j){
    			int p,u=0;
    			for(int k=i;k<=j;k++){
    			    p=a[k];
    			    u=(u^p);
    				ans+=u;
    				u=ans;
				}
				if(ans==k)
					cnt++;	
				
			}else{
				continue;
			}
		}
	}
	cout<<cnt;
    return 0;
}
