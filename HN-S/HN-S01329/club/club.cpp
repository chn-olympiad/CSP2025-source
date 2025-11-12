#include<bits/stdc++.h>
using namespace std;

int a1[400000];
int a2[400000];
int a3[400000];
int na,nb,nc;
bool f[400000];
int ans;

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			a1[i]=a;
			a2[i]=b;
			a3[i]=c;
		}
		for(int i=1;i<=n;i++){
			int a=0,b=0,c=0;
			for(int j=1;j<=n;j++){
				if(f[j])continue;
				if(a1[a]<=a1[j]&&na<n/2){			
					a=j;					
				}				
			}
			na++;
			f[a]=1;
			for(int j=1;j<=n;j++){
				if(f[j])continue;
				if(a2[b]<=a2[j]&&nb<n/2){
					b=j;					
				}				
			}
			nb++;
			f[b]=1;
			for(int j=1;j<=n;j++){
				if(f[j])continue;
				if(a3[c]<=a3[j]&&!f[j]&&nc<n/2){
					c=j;					
				}
			}
			nc++;
			f[c]=1;
			ans+=a1[a]+a2[b]+a3[c];
		}
		cout<<ans;
		ans=0;
	}
	return 0;
		
}
