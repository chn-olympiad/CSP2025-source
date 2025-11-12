#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int n,k,ans;
bool flagA=1,flagB=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flagA=0;
        if(a[i]>=2) flagB=0;
        b[i]=b[i-1]^a[i];
    }
    if(k==0&&flagA){
		ans=n/2;
		
    }else if(k==1&&flagB){
		for(int i=1;i<=n;i++){
		    if(a[i]==1) ans++;
		}
    }else if(k==0&&flagB){
	    int cnt=0;
	    for(int i=1;i<=n;i++){
		    if(a[i]==0){
			    ans+=cnt/2+1;
			    cnt=0;
			}
		    else cnt++;
	    }
	    ans+=cnt/2;
	}else{
		int cnt=1;
	    for(int r=1;r<=n;r++){
			if(a[r]==k){
			    ans++;
			    cnt=r+1;
			}else{
				for(int l=cnt;l<r;l++){
					if(abs(b[r]^b[l-1])==k){
						ans++;
						cnt=r+1;
						break;
					}
				}
			}
		    
			
		}
	}
    cout<<ans;
    return 0;
}
