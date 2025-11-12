#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500005],tot,s,t;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
    }
    if(k==0&&ans==n){
       cout<<n/2;
    }
    else {
		if(k==1){
		tot++;
		for(int i=tot;i<=n;i++){
		    if(a[i]!=a[i+1]){
				s++;
				i=i+2;
			}
		    else if(a[i]==a[i+1]&&a[i+1]==a[i+2]&&a[i]==1){
				s++;
				i+=3;
			}
		}
		cout<<s;
	}
	    if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)t++;
				else if(a[i]==a[i+1]&&a[i]==1){
					t++;
					i+=2;
			}
		}	
		cout<<t;
	}
    }
    return 0;
}
