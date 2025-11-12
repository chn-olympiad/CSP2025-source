//GZ-S00189 贵州省务川中学 徐好乐 
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=1e5+10;

long long n,a[N],b[N],c[N];
long long ans=0;

long long max(long long a,long long b) {
	return a>b?a:b;
}

bool cmp(long long a,long long b){
	return a>b;
}

void dfs(long long x,long long an,long long bn,long long cn,long long cnt){
	
	if(an>n/2 || bn>n/2 ||cn>n/2){
		return;
	}
	if(x==n){
		ans=max(cnt,ans);
		return;
	}
	
	
	dfs(x+1,an+1,bn,cn,cnt+a[x+1]);
	dfs(x+1,an,bn+1,cn,cnt+b[x+1]);
	dfs(x+1,an,bn,cn+1,cnt+c[x+1]);
	
	
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    
    int t;
    
    cin>>t;
    while(t--){
       
	    cin>>n;
	    if(n<=200){
	    	for(int i=1;i<=n;i++){
	        	cin>>a[i]>>b[i]>>c[i];
		    }
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
			ans=0;
		}
		else{
		    bool a1=0,b1=0,c1=0;
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
				if(a[i]!=0) a1=1;
				if(b[i]!=0) b1=1;
				if(c[i]!=0) c1=1;	
			}
			if(a1==b1 && b1==c1){
				dfs(0,0,0,0,0);
    	        cout<<ans<<endl;
    	        ans=0;
			}
			else{
				sort(a+1,a+1+N,cmp);
				for(int i=1;i<=n/2;i++){
					ans+=a[i];
				}
				cout<<ans<<endl;
				ans=0;
			}
		}
	    
	}
	
	return 0;
	
} 
