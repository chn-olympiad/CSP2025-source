#include<bits/stdc++.h>
using namespace std;
int t,n,ca,cb,cc;
long long ans;
struct l{
	int a,b,c;
}s[500005];
queue<l>q,qa,qb,qc;
bool cmp(l a,l b){
	if(a.a<b.a){
		return 0;
		
	}else if(a.a>b.a){
		return 1;
	}else{
		if(a.b<b.b){
			return 0;
		}else if(a.b>b.b){
			return 1;
		}else{
			return a.b>b.b;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		ca=0;
		cb=0;
		cc=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&s[i].a,&s[i].b,&s[i].c);
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			q.push(s[i]);
		}
		while(!q.empty()){
			l f=q.front();
			if(f.a==max({f.a,f.b,f.c})){
				if(ca==n/2){
					int cnt=ca-1;
					while(cnt--){
						l fa=qa.front();
						qa.pop();
						qa.push(fa);
					}
					cnt=ca;
					while(cnt--){
						l fa=qa.front();
						qa.pop();
						if(fa.b+f.a>fa.a+f.b){
							qa.push(f);
							qb.push(fa);
							cb++;
							break;
						}else if(fa.c+f.a>fa.a+f.c){
							qa.push(f);
							qc.push(fa);
							cc++;
							break;
						}else{
							qa.push(fa);
						}
					}
					if(f.b>f.c){
						qb.push(f);
						cb++;
					}else{
						qc.push(f);
						cc++;
					}
				}else if(ca>n/2){
					while(ca>n/2){
						if(cb<n/2){
							qb.push(qa.front());
							qa.pop();
							ca--;
							cb++;
						}else if(cc<n/2){
							qc.push(qa.front());
							qa.pop();
							ca--;
							cc++;
						}
					}
				}else{
					qa.push(f);
				    q.pop();
				    ca++;
				    continue;
				}
			}
			if(f.b==max({f.a,f.b,f.c})){
				if(cb==n/2){
					int cnt=cb-1;
					while(cnt--){
						l fa=qb.front();
						qb.pop();
						qb.push(fa);
					}
					cnt=cb;
					while(cnt--){
						l fa=qb.front();
						qb.pop();
						if(fa.a+f.b>fa.b+f.a){
							qb.push(f);
							qa.push(fa);
							ca++;
							break;
						}else if(fa.c+f.b>fa.b+f.c){
							qb.push(f);
							qc.push(fa);
							cc++;
							break;
						}else{
							qb.push(fa);
						}
					}
					if(f.a>f.c){
						qa.push(f);
						ca++;
					}else{
						qc.push(f);
						cc++;
					}	
				}else if(cb>n/2){
					while(cb>n/2){
						if(ca<n/2){
							qa.push(qb.front());
							qb.pop();
							cb--;
							ca++;
						}else if(cc<n/2){
							qc.push(qb.front());
							qb.pop();
							cb--;
							cc++;
						}
					}
				}else{
					qb.push(f);
				    q.pop();
				    cb++;
				    continue;
				}
			}
			if(f.c==max({f.a,f.b,f.c})){
				if(cc==n/2){
					int cnt=cc-1;
					while(cnt--){
						l fa=qc.front();
						qc.pop();
						qc.push(fa);
					}
					cnt=cc;
					while(cnt--){
						l fa=qc.front();
						qc.pop();
						if(fa.b+f.c>fa.c+f.b){
							qc.push(f);
							qb.push(fa);
							cb++;
							break;
						}else if(fa.a+f.c>fa.c+f.a){
							qc.push(f);
							qa.push(fa);
							ca++;
							break;
						}else{
							qc.push(fa);
						}
					}
					if(f.a>f.b){
						qa.push(f);
						ca++;
					}else{
						qb.push(f);
						cb++;
					}	
				}else if(cc>n/2){
					while(cc>n/2){
						if(cb<n/2){
							qb.push(qc.front());
							qc.pop();
							cc--;
							cb++;
						}else if(ca<n/2){
							qa.push(qc.front());
							qc.pop();
							cc--;
							ca++;
						}
					}
				}else{
					qc.push(f);
				    q.pop();
				    cc++;
				    continue;
				}
			}
		}
		//tong 3 ji 4
		while(!qa.empty()){
			ans+=qa.front().a;
			qa.pop();
		}
		while(!qb.empty()){
			ans+=qb.front().b;
			qb.pop();
		}
		while(!qc.empty()){
			ans+=qc.front().c;
			qc.pop();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
