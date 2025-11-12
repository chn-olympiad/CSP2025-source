#include<bits/stdc++.h>
using namespace std;
int ans,t,n;
bool flag=true,flag1=true;
struct Nove{
	int v,a,b,c;
	bool operator < (const Nove &A){
		return v<A.v;
	} 
}a[114514],b[114514],c[114514];
struct Info{
	int a,b,c,k;
	bool operator < (const Info &A){
		return k<A.k;
	} 
}s[114514];
void dfs(int dep,int la,int lb,int lc,int sum){
	if(la>n/2||lb>n/2||lc>n/2){
		return ;
	}
	if(dep>n){
		ans=max(ans,sum);
		return ;
	}
	dfs(dep+1,la+1,lb,lc,sum+a[dep].v);
	dfs(dep+1,la,lb+1,lc,sum+b[dep].v);
	dfs(dep+1,la,lb,lc+1,sum+c[dep].v);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].v>>b[i].v>>c[i].v;
			s[i].a=a[i].v,s[i].b=b[i].v,s[i].c=c[i].v;
			s[i].k=max(s[i].a,s[i].b);
			if(c[i].v!=0){
				flag=false;
				flag1=false;
			}
			if(b[i].v!=0){
				flag=false;
			}
		}
		if(n==2){
			int k[10];
			k[1]=a[1].v+b[2].v;
			k[2]=a[1].v+c[2].v;
			k[3]=b[1].v+a[2].v;
			k[4]=b[1].v+c[2].v;
			k[5]=c[1].v+a[2].v;
			k[6]=c[1].v+b[2].v;
			sort(k+1,k+6+1);
			cout<<k[6]<< endl;
			continue;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<< endl;
			continue;
		}
		if(flag){
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2;i--){
				ans+=a[i].v;
			}
		}else{
			if(flag1){
				int la=0,lb=0;
				for(int i=1;i<=n;i++){
					if(s[i].a>s[i].b){
						if(la<n/2){
							la++;
							ans+=s[i].a;
						}else{
							lb++;
							ans+=s[i].b;
						}
					}else{
						if(lb<n/2){
							lb++;
							ans+=s[i].b;
						}else{
							la++;
							ans+=s[i].a; 
						}
					}
				}
			}else{
				int x=0,y=0,z=0;
				for(int i=n;i>=1;i--){
					if(s[i].a>=s[i].b&&s[i].a>=s[i].c&&x<n/2){
						x++;
						ans+=s[i].a;
					}else if(s[i].b>s[i].a&&s[i].b>s[i].c&&y<n/2){
						y++;
						ans+=s[i].b; 
					}else{
						if(z<n/2){
							z++;
							ans+=s[i].c;
						}else{
							if(s[i].a>s[i].b){
								if(x<n/2){
									x++;
									ans+=s[i].a;
								}else{
									y++;
									ans+=s[i].b;
								}
							}else{
								if(y<n/2){
									y++;
									ans+=s[i].b;
								}else{
									ans+=s[i].a;
								}
							}
						}
					}
				}
			}
		}
		cout<<ans<< endl;
	}
}
