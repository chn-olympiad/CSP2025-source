#include<bits/stdc++.h>

using namespace std;
 
int n,k;
int a[500010];
int ans=0;
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
 	cin>>n>>k;
 	for(int i=1;i<=n;i++) cin>>a[i];
 	int l=1,r=0;
 	int xnum=0;
 	bool f=false;
 	while(l<=n){
 		
 		if(xnum==k&& f){
 			ans++;
 			
 			l=r+1;
 			r=l-1;
 			xnum=0;
		}
		else{
			r++;
			f=true;
			if(r>n){
				l++;
				r=l-1;
				xnum=a[r];
			}
			else{
				xnum^=a[r];
			}
		}
	}
	cout<<ans<<endl<<ans;
	return 0;
}
