#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int ca=0,cb=0,cc=0,na=0,nb=0,nc=0;
struct wr{
	int a,b,c;
};
bool cmp(wr aa,wr bb){
	int mxa=max(aa.a,max(aa.b,aa.c)),mxb=max(bb.a,max(bb.b,bb.c));
	return mxa>mxb;
}
void solve(){
	cin>>n;
	int cel=n/2;
	wr r[N];
	for(int i=1;i<=n;i++)cin>>r[i].a>>r[i].b>>r[i].c;
	sort(r+1,r+n+1,cmp);
	for(int i=1;i<=n;i++){
		int mx=max(max(r[i].a,r[i].b),r[i].c);
		if(mx==r[i].a){
			if(na<cel){
				ca+=r[i].a;
				na++;
			}else{
				for(int j=1;j<=n;j++){
					int pmx=max(r[j].c,r[j].a);
					if(r[i].a>mx&&na==cel){
						ca+=r[i].a;
						if(pmx==r[j].b){
							cb-=r[j].b;nb--;
						}else{
							cc-=r[j].c;nc--;
						}
					}
				}
				mx=max(r[i].b,r[i].c);
				if(mx==r[i].b){
					if(nb<cel){
						cb+=r[i].b;
						nb++;
					}else{
						for(int j=1;j<=n;j++){
							if(r[i].b<mx&&nb==cel){
								cb+=r[i].b;
							cc-=r[j].c;nc--;
							}
						}
						cc+=r[i].c;nc++;
					}
				}else{
					if(nc<cel){
						cc+=r[i].c;
						nc++;
					}else{
						for(int j=1;j<=n;j++){
							if(r[i].c<mx&&nc==cel){
								cc+=r[i].c;
							cb-=r[j].b;nb--;
							}
						}
						cb+=r[i].b;nb++;
					}
				}
			}
		}else if(max(max(r[i].a,r[i].b),r[i].c)==r[i].b){
			if(nb<cel){
				cb+=r[i].b;
				nb++;
			}else{
				for(int j=1;j<=n;j++){
					int pmx=max(r[j].c,r[j].a);
					if(r[i].b>mx&&nb==cel){
						cb+=r[i].b;
						if(pmx==r[j].a){
							ca-=r[j].a;na--;
						}else{
							cc-=r[j].c;nc--;
						}
					}
				}
				mx=max(r[i].a,r[i].c);
				if(mx==r[i].a){
					if(na<cel){
						ca+=r[i].a;
						na++;
					}else{
						for(int j=1;j<=n;j++){
							if(r[i].a<mx&&na==cel){
								ca+=r[i].a;
							cc-=r[j].c;nc--;
							}
						}
						cc+=r[i].c;nc++;
					}
				}else{
					if(nc<cel){
						cc+=r[i].c;nc++;
					}else{
						for(int j=1;j<=n;j++){
							if(r[i].c<mx&&nc==cel){
								cc+=r[i].c;
							ca-=r[j].a;na--;
							}
						}
						ca+=r[i].a;na++;
					}
				}
			}
		}

		else{
			if(nc<cel){
				cc+=r[i].c;nc++;
			}else{
				for(int j=1;j<=n;j++){
					int pmx=max(r[j].b,r[j].a);
					if(r[i].c>mx&&nc==cel){
						cc+=r[i].c;
						if(pmx==r[j].b){
							cb-=r[j].b;nb--;
						}else{
							ca-=r[j].a;na--;
						}
					}
				}
				mx=max(r[i].b,r[i].a);
				if(mx==r[i].b){
					if(nb<cel){
						cb+=r[i].b;nb++;
					}else{
						for(int j=1;j<=n;j++){
							if(r[i].b<mx&&nb==cel){
								cb+=r[i].b;
							ca-=r[j].a;na--;
							}
						}
						ca+=r[i].a;na++;
					}
				}else{
					if(na<cel){
						ca+=r[i].a;na++;
					}else{
						for(int j=1;j<=n;j++){
							if(r[i].a<mx&&na==cel){
								ca+=r[i].a;
							cb-=r[j].b;nb--;
							}
						}
						cb+=r[i].b;nb++;
					}
				}
			}
		}
	}
	cout<<ca+cb+cc<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		ca=0,cb=0,cc=0,na=0,nb=0,nc=0;
		solve();
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
