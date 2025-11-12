#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
inline void read(int &x){
	x=0;
	int f=1;
	char c;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x*=f;
}
inline bool cmp(PII a,PII b){
	return a.first<b.first;
}
int cnta,cntb,cntc,Cnta=0,Cntb=0,Cntc=0;
int t,n;
PII a[200005];
PII b[200005];
PII c[200005];
int vis[200005];
int ans=0;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		ans=0;
		read(n);
//		cout<<n<<'\n';
		for(int i=1;i<=n;i++){
			read(a[i].first);
			read(b[i].first);
			read(c[i].first);
			a[i].second=i;
			b[i].second=i;
			c[i].second=i;
		}	
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
//		for(int i=n;i>=1;i--){
//			cout<<c[i].first<<' '<<b[i].first<<' '<<a[i].first<<'\n';
//		}
		cnta=cntb=cntc=n;
		Cnta=Cntb=Cntc=0;
		for(int i=1;i<=n;i++){
			jj:
//			cout<<Cnta<<' '<<Cntb<<' '<<Cntc<<' ';
			if(Cnta<n/2&&Cntb<n/2&&Cntc<n/2){
//				cout<<"Yes ";
				if(a[cnta].first>b[cntb].first){		
					if(c[cntc].first>a[cnta].first){
						if(!vis[c[cntc].second]){
							vis[c[cntc].second]=1;
							ans+=c[cntc].first;
//							cout<<'C'<<c[cntc].first<<'\n';
							cntc--;
							Cntc++;
						}else{
							cntc--;
							goto jj;
						}
					}else{
						if(!vis[a[cnta].second]){
							vis[a[cnta].second]=1;
							ans+=a[cnta].first;
//							cout<<'A'<<a[cnta].first<<'\n';
							cnta--;
							Cnta++;
						}else{
							cnta--;
							goto jj;
						}
					}
				}else{
					if(c[cntc].first>b[cntb].first){
						if(!vis[c[cntc].second]){
							vis[c[cntc].second]=1;
							ans+=c[cntc].first;
//							cout<<'C'<<c[cntc].first<<'\n';
							cntc--;
							Cntc++;
						}else{
							cntc--;
							goto jj;
						}
					}else{
						if(!vis[b[cntb].second]){
							vis[b[cntb].second]=1;
							ans+=b[cntb].first;
//							cout<<'B'<<b[cntb].first<<'\n';
							cntb--;
							Cntb++;
						}else{
							cntb--;
							goto jj;
						}
					}
				}
			}else if(Cnta>=n/2){
				if(c[cntc].first>b[cntb].first){
					if(!vis[c[cntc].second]){
						vis[c[cntc].second]=1;
						ans+=c[cntc].first;
//						cout<<'C'<<c[cntc].first<<'\n';
						cntc--;
						Cntc++;
					}else{
						cntc--;
						goto jj;
					}
				}else{
					if(!vis[b[cntb].second]){
						vis[b[cntb].second]=1;
						ans+=b[cntb].first;
//						cout<<'B'<<b[cntb].first<<'\n';
						cntb--;
						Cntb++;
					}else{
						cntb--;
						goto jj;
					}
				}
			}else if(Cntb>=n/2){
				if(c[cntc].first>a[cnta].first){
					if(!vis[c[cntc].second]){
						vis[c[cntc].second]=1;
						ans+=c[cntc].first;
//						cout<<'C'<<c[cntc].first<<'\n';
						cntc--;
						Cntc++;
					}else{
						cntc--;
						goto jj;
					}
				}else{
					if(!vis[a[cnta].second]){
						vis[a[cnta].second]=1;
						ans+=a[cnta].first;
//						cout<<'A'<<a[cnta].first<<'\n';
						cnta--;
						Cnta++;
					}else{
						cnta--;
						goto jj;
					}
				}
			}else{
				if(a[cnta].first>b[cntb].first){
					if(!vis[a[cnta].second]){
						vis[a[cnta].second]=1;
						ans+=a[cnta].first;
//						cout<<'A'<<a[cnta].first<<'\n';
						cnta--;
						Cnta++;
					}else{
						cnta--;
						goto jj;
					}
				}else{
					if(!vis[b[cntb].second]){
						vis[b[cntb].second]=1;
						ans+=b[cntb].first;
//						cout<<'B'<<b[cntb].first<<'\n';
						cntb--;
						Cntb++;
					}else{
						cntb--;
						goto jj;
					}
				}
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) vis[i]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

