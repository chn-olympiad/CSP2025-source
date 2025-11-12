#include <bits/stdc++.h>
using namespace std;
int a[100005][5],maxn[100005],b[100005],c[100005],maxx=0,p=0;
int cnt1,cnt2,cnt3,ans;
int main(){
	freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);	
    int t;
    scanf("%d",&t);
    while(t--){
	    int n;
	    scanf("%d",&n);
	    for(int i=1;i<=n;i++){
			c[i]=i;
		    for(int j=1;j<=3;j++){
			    cin>>a[i][j];	
			    if(a[i][j]>maxx){
				    maxx=a[i][j];
				    p=j;	
				}
			}
			maxn[i]=maxx;
			maxx=0;
			b[i]=p;
			p=0;	
		}
		for(int i=1;i<n;i++){
		    for(int j=1;j<n;j++){
			    if(maxn[j]>maxn[j+1]){
				    swap(maxn[j],maxn[j+1]);
				    swap(b[j],b[j+1]);
				    swap(c[j],c[j+1]);	
				}	
			}	
		}
	    for(int k=n;k>=1;k--)ans+=maxn[k];
	    cout<<ans<<endl;
	    ans=0;
	   }
    return 0;	
}
