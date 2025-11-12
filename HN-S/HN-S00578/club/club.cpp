#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a1[N],a2[N],a3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,p=0,q=0;
	cin>>t;
	while(t--){
		cin>>n;
		long long ans=0;
		int ren1=0;
		for(int i=1;i<=n;i++){
	        cin>>a1[i]>>a2[i]>>a3[i];
	        if(a2[i]==0&&a3[i]==0){
	        	p++;
			}
			else{
				if(a3[i]==0){
					q++;
				}
			}
	    }
	    if(p==n){
	    	sort(a1+1,a1+1+n);
	    	for(int i=n;i>=n/2;i--){
	    	    ans+=a1[i];
		    }
		}
		else{
			if(q==n){
				for(int i=1;i<=n;i++){
					if(a1[i]>a2[i]&&ren1<n/2){
						ans+=a1[i];
						ren1++;
					}
					else{
						ans+=a2[i];
					}
				}
			}
		}
	    cout<<ans;
	}
	return 0;
} 
