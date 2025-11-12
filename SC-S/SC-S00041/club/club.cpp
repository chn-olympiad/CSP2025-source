#include<bits/stdc++.h>
using namespace std;
int n,t;
int f[205][205][205];
struct node{
	int a,b,c,d;
}s[100005];
bool cmp(node o,node p){
	return o.a>p.a;
}
bool cmp2(node o,node p){
	return o.d>p.d;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int mx=0,mx2=0,sum=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					f[i][j][k]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			mx=max(mx,s[i].b);
			mx2=max(mx2,s[i].c);
			s[i].d=s[i].b-s[i].a;
			sum+=s[i].a;
		}
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					for(int k=0;k<=min(n/2,i-j);k++){
						int l=i-j-k;
						if(l>n/2)continue;
						if(j>0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+s[i].a);
						if(k>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+s[i].b);
						if(l>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+s[i].c);
					}
				}
			}
			int ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=1;j<=n/2;j++){
					int k=n-i-j;
					if(k>n/2)continue;
					ans=max(ans,f[n][i][j]);
				}
			}
			cout<<ans<<endl;
		}else{
			if(mx==0&&mx2==0){
				sort(s+1,s+1+n,cmp);
				int ans=0;
				for(int i=1;i<=n/2;i++){
					ans+=s[i].a;
				}
				cout<<ans<<endl;
			}else if(mx2==0){
				sort(s+1,s+1+n,cmp2);
				cout<<sum<<endl; 
				for(int i=1;i<=n/2;i++){
					if(s[i].d<=0)break;
					sum+=s[i].d;
				}
				cout<<sum<<endl;
			}
		}
	}
	
	return 0;
}