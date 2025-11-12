#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	int a,b,c;
}stu[100005];
void dfs(long long sa,long long sb,long long sc,int na,int nb,int nc,int x){
	if(x==n+1){
		ans=max(ans,sa+sb+sc);
	}if(na+1<=n/2){
		dfs(sa+stu[x].a,sb,sc,na+1,nb,nc,x+1);
	}if(nb+1<=n/2){
		dfs(sa,sb+stu[x].b,sc,na,nb+1,nc,x+1);
	}if(nc+1<=n/2){
		dfs(sa,sb,sc+stu[x].c,na,nb,nc+1,x+1);
	}
}int dp[205][205];
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>stu[i].a>>stu[i].b>>stu[i].c;
		if(n<=30){
			dfs(0,0,0,0,0,0,1);
			cout<<ans<<"\n";
		}else if(stu[1].b==0 && stu[1].c==0){
			sort(stu+1,stu+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=stu[i].a;
			cout<<ans<<"\n";
		}else if(stu[1].c==0){
			int as=0,bs=0,u=0;
			sort(stu+1,stu+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(stu[i].a>stu[i].b){
					ans+=stu[i].a;
					as++;
				}
				else if(stu[i].b>stu[i].a){
					ans+=stu[i].b;
					bs++;
				}else{
					ans+=stu[i].a;
					as++;
					u++;
				}
			}if(as-u>n/2){
				vector<int> vi;
				long long sum=0;
				for(int i=1;i<=n;i++){
					if(stu[i].a>stu[i].b){
						vi.push_back(stu[i].a-stu[i].b);
					}
				}sort(vi.begin(),vi.end());
				for(int i=0;i<as-u-n/2;i++) ans-=vi[i];
			}if(bs-u>n/2){
				vector<int> vi;
				long long sum=0;
				for(int i=1;i<=n;i++){
					if(stu[i].b>stu[i].a){
						vi.push_back(stu[i].b-stu[i].a);
					}
				}sort(vi.begin(),vi.end());
				for(int i=0;i<bs-u-n/2;i++) ans-=vi[i];
			}
			cout<<ans<<"\n";
		}
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
