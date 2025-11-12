#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],sum=0;
bool x[50003];
void dfs(int tip,int ans,int time,int pre){
                  
	if(a[tip]>=b[tip]-ans||time>tip-3){      
	                    
		return;                                            
	}        
	sum++;
	sum=sum%998244353;
	for(int j=pre;j<tip;j++){
		if(x[j]!=0){                                                    
		    
			if(a[tip]>=b[tip]-(ans+a[j])||time+1>tip-3){
				break;
			}
			x[j]=0;
			dfs(tip,ans+a[j],time+1,j);
			x[j]=1;
			
			
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i+1]=b[i]+a[i];
	}
	for(int i=3;i<=n;i++){
		memset(x,1,sizeof(x));
		dfs(i,0,0,1);
	}
	cout<<sum;
	return 0;
}