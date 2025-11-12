#include <bits/stdc++.h>
using namespace std;
int a[100005][10],b[10],c[10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		long long maxn=0,p=0,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(maxn<a[i][j]){
					maxn=a[i][j];
					p=j;
				}
			}
			if(n==2)
			{
				if(b[p]==0)
				{
					b[p]++;
				    sum+=maxn;
				    c[p]=maxn;
				    maxn=0;
				}
				else{
				    if(maxn<=c[p]){
					    maxn=0;
					    for(int k=1;k<=3;k++){
						    if(k==p) continue;
						    if(maxn<a[i][k]) maxn=a[i][k];
				    	}
				    	sum+=maxn;
			    	}
			    	else{
				    	sum=maxn;
				    	maxn=0;
				    	for(int k=1;k<=3;k++){
					    	if(k==p) continue;
					    	if(maxn<a[i][k]) maxn=a[i][k];
					    }
					    sum+=maxn;
					    maxn=0;
				    }
			    }
			}
			else{
			    if((b[p]<=(n/2))){
			    	b[p]++;
			    	sum+=maxn;
			    	c[p]=maxn;
			    	maxn=0;
		    	}
		    	else{
				    if(maxn<=c[p]){
				    	maxn=0;
				    	for(int k=1;k<=3;k++){
				    		if(k==p) continue;
				    		if(maxn<a[i][k]) maxn=a[i][k];
				    	}
				    	sum+=maxn;
			    	}
			    	else{
				    	sum=maxn;
					    maxn=0;
				    	for(int k=1;k<=3;k++){
				    		if(k==p) continue;
				    		if(maxn<a[i][k]) maxn=a[i][k];
				    	}
				    	sum+=maxn;
				    	maxn=0;
				    }
			    }
	        }
	    }
	    cout<<sum<<'\n';
	}
	return 0;
} 
