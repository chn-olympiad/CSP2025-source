#include<bits/stdc++.h>
using namespace std;
struct h{
    int a=0,b=0,c=0;
}x[100010];
int maxn=0,t,n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int e=1;e<=t;e++){
    	maxn=0;
    	cin>>n;
    	for(int i=1;i<=n;i++) cin>>x[i].a>>x[i].b>>x[i].c;
    	for(int i=0;i<=n;i++){
    		for(int j=0;j!=i&&j<=n;j++){
    			for(int k=0;k!=i&&k!=j&&k<=n;k++){
    				maxn=max(x[i].a+x[j].b+x[k].c,maxn);
				}
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
