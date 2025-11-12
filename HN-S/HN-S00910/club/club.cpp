#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t;
int n,a[N],b[N],c[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int k1=0,k2=0,k3=0;
		int ans = 0;
	    cin>>n;
	    for(int i=1;i<=n;i++){
	    cin>>a[i]>>b[i]>>c[i];
		sort(a+1,a+1+n,cmp);
	    sort(b+1,b+1+n,cmp);
	   	sort(c+1,c+1+n,cmp);
	    	if(n==2){
	    		if(max(a[i],max(b[i],c[i]))==a[i]){
	    			k1 += 1;
	    			ans += a[i];
	    			if(k1/2>n){
	    				ans = ans-a[i]+max(b[i],c[i]);
	    				break;
					}
				}
				else if(max(b[i],max(a[i],c[i]))==b[i]){
	    			k2 += 1;
	    			ans += b[i];
	    			if(k2/2>n){
	    				ans = ans-b[i]+max(a[i],c[i]);
	    				break;
					}
				}
				else if(max(c[i],max(b[i],a[i]))==c[i]){
	    			k3 += 1;
	    			ans += c[i];
	    			if(k3/2>n){
	    				ans = ans-c[i]+max(a[i],b[i]);
	    				break;
					}
				}
			}
			else{
				if(max(a[i],max(b[i],c[i]))==a[i]){
	    			k1 += 1;
	    			ans += a[i];
	    			if(k1/2>n){
	    				ans = ans-a[i]+max(b[i],c[i]);
	    				break;
					}
				}
				else if(max(b[i],max(a[i],c[i]))==b[i]){
	    			k2 += 1;
	    			ans += b[i];
	    			if(k2/2>n){
	    				ans = ans-b[i]+max(a[i],c[i]);
	    				break;
					}
				}
				else if(max(c[i],max(b[i],a[i]))==c[i]){
	    			k3 += 1;
	    			ans += c[i];
	    			if(k3/2>n){
	    				ans = ans-c[i]+max(a[i],b[i]);
	    				break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
