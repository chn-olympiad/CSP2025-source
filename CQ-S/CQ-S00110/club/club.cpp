#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005],c[100005];
int t[100005];
long long maxx;
void dfs(int x,long long ans,int aa,int bb,int cc){
	if(x>n){
		maxx=max(maxx,ans);
		return;
	}
	if(aa<n/2) dfs(x+1,ans+a[x],aa+1,bb,cc);
	if(bb<n/2) dfs(x+1,ans+b[x],aa,bb+1,cc);
	if(cc<n/2) dfs(x+1,ans+c[x],aa,bb,cc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n<=30){//暴力
		    maxx=0;
		    dfs(1,0,0,0,0);
			cout<<maxx<<'\n';
			continue;
		}
		if(n<=200){//性质B
			int aa=0,bb=0;
			long long ans=0;
			for(int i=1;i<=n;i++){
				t[i]=0;
				if(a[i]>=b[i]){
					if(aa<n/2){
					    t[i]=1;
					    ans+=a[i];
					    aa++;
				    }
				    else{
				    	int maxn=0,k=-1;
				    	for(int j=1;j<i;j++){
				    		if(t[j]==2) continue;
				    		if((a[i]-b[i])-(a[j]-b[j])>maxn){
				    			maxn=(a[i]-b[i])-(a[j]-b[j]);
				    			k=j;
							}
						}
						if(k==-1){
							ans+=b[i];
							t[i]=2;
							continue;
						}
						t[k]=2,t[i]=1;
						ans+=b[k]-a[k]+a[i];
					}
				}
				if(b[i]>a[i]){
					if(bb<n/2){
					    t[i]=2;
					    ans+=b[i];
					    bb++;
				    }
				    else{
				    	int maxn=0,k=-1;
				    	for(int j=1;j<i;j++){
				    		if(t[j]==1) continue;
				    		if((b[i]-a[i])-(b[j]-a[j])>maxn){
				    			maxn=(b[i]-a[i])-(b[j]-a[j]);
				    			k=j;
							}
						}
						if(k==-1){
							ans+=a[i];
							t[i]=1;
							continue;
						}
						t[k]=1,t[i]=2;
						ans+=a[k]-b[k]+b[i];
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
	    if(n<=100000){
	    	bool aaa=1,bbb=1;
	    	for(int i=1;i<=n;i++){
	    		if(c[i]!=0) aaa=bbb=0;
	    		if(b[i]!=0) aaa=0;
			}
			if(aaa==1){//性质A 
			    long long ans=0;
			    sort(a+1,a+n+1);
			    for(int i=n;i>n/2;i--){
		    		ans+=a[i];
			    }
			    cout<<ans<<'\n';
		    	continue;
			}
		    if(bbb==1){//性质B
		    	int aa=0,bb=0;
			    long long ans=0;
		    	for(int i=1;i<=n;i++){
				    t[i]=0;
				    if(a[i]>=b[i]){
				        if(aa<n/2){
					        t[i]=1;
					        ans+=a[i];
					        aa++;
				        }
				        else{
				        	int maxn=0,k=-1;
				        	for(int j=1;j<i;j++){
				    	    	if(t[j]==2) continue;
				    		    if((a[i]-b[i])-(a[j]-b[j])>maxn){
				    			    maxn=(a[i]-b[i])-(a[j]-b[j]);
       				    			k=j;
    							}
	    					}
		    				if(k==-1){
			    				ans+=b[i];
				    			t[i]=2;
					    		continue;
						    }
    						t[k]=2,t[i]=1;
	    					ans+=b[k]-a[k]+a[i];
		    			}
			    	}
				    if(b[i]>a[i]){
					    if(bb<n/2){
					        t[i]=2;
    					    ans+=b[i];
	    				    bb++;
		    		    }
			    	    else{
				        	int maxn=0,k=-1;
				        	for(int j=1;j<i;j++){
				    	    	if(t[j]==1) continue;
				    		    if((b[i]-a[i])-(b[j]-a[j])>maxn){
				    			    maxn=(b[i]-a[i])-(b[j]-a[j]);
				    			    k=j;
							    }
						    }
    						if(k==-1){
	    						ans+=a[i];
		    					t[i]=1;
			    				continue;
    						}
	    					t[k]=1,t[i]=2;
		    				ans+=a[k]-b[k]+b[i];
			    		}
				    }
			    }
    			cout<<ans<<'\n';
	    		continue;
		    }
		    cout<<"0\n";
		}
	}
	return 0;
}
