#include<bits/stdc++.h>
using namespace std;
long long t,n,h;
long long a[100],b[100],c[100],d[100][100],e[100][100],ans[40];
long long y[100],k[100],g[100],pop[100],pup[100],mix[100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;int cpu=0,lo=0;
	for(int i=0;i<t;i++){
		cin>>n; 
		int hu=n,mn;
		ans[i]=n/2;
		h=ans[i];
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
			e[i][j]=max(c[j],b[j]);	
			pup[i]=e[i][j];
			if(pup[i]<pup[i-1]){
				int d=pup[i];
				pup[i]=pup[i-1];
				pup[i-1]=d;
		    }
		    d[i][j]=max(e[i][j],a[j]);
		    pop[i]+=d[i][j];
		    mix[i]=d[i][j];
		    if(d[i][j]==a[j])y[i]++;
		    if(y[i]>h){
		    	for(int mn=0;mn<ans[i];mn++)pop[i]=pop[i]-mix[mn];
		    	for(int d=ans[i];d<=i;d++)pop[i]+=pup[i];
			}
			if(d[i][j]==b[j])k[i]++;
			if(k[i]>h){
		    	for(int mn=0;mn<ans[i];mn++)pop[i]-=mix[mn];
		    	for(int d=ans[i];d<=n;d++)pop[i]+=pup[i];
			}	
			if(d[i][j]==c[j])g[i]++;
			if(g[i]>h){
		    	for(int mn=0;mn<ans[i];mn++)pop[i]-=mix[mn];
		    	for(int d=ans[i];d<=n;d++)pop[i]+=pup[i];
			}	
		}
	}	

	for(int i=0;i<t;i++){
			cout<<pop[i]<<endl;
		
	}
	
	return 0;
}





