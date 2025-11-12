//I am sunshineEmilo-20251101.
#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;	
	int d;
}ren[100005];
void dfs(long long sum1,long long sum2,long long sum3,long long num1,long long num2,long long num3,long long idx){
	if(idx==n){
		maxsum=max(maxsum,sum1+sum2+sum3);
	}else{
		if(num_a+1<=n/2){
			dfs(sum1+ren[idx].a,sum2,sum3,num1+1,num2,num3,idx+1);
		}
		if(num2+1<=n/2){
			dfs(num2+ren[idx+1].b,sum2,sum3,num1+2,num2,num3,idx+2);
		}
	}
}
bool cmp(node x,node y){
	if(x.a!=y.a){return x.a>y.a;}
	else if(x.b!=y.b){return x.b>y.b;}
	else{return x.c>y.c;}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	int n;
	while(t--){
		cin>>n;
		vector<node> xs; vector<node> ys; vector<node> zs;
		long long asum=0;long long bsum=0;long long csum=0;
		for(int i=1;i<=n;i++){
			cin>>ren[i].a>>ren[i].b>>ren[i].c;
			int max_value=max(ren[i].a,max(ren[i].b,ren[i]));
			if(max_value==ren[i].a){
				ren[i].d=1;
				push_back(ren[i]);
				asum+=ren[i].a;
			}
			else if(max_value==ren[i].b){
				ren[i].d=2;
				push_back(ren[i]);
				bsum+=ren[i].b;
			}else if(max_value==ren[i].c){
				ren[i].d=3;
				push_back(ren[i]);
				csum+=ren[i].c;
			}
			
			bool flag1=true,flag2=true;
			if(flag==true){
				long long ans=0;
				sort(ren+1,ren+n+1,cmp);
				for(int i=1;i<=n/2;i++){
					ans+=ren[i].a;
				}	
			cout<<ans<<endl;
			}else if(flag2==true){
				long long ans1=0,ans2=0
				sort(ren+1,ren+n+1,cmp2);
				for(int i=1;i<=n/2;i++){
					ans1+=ren[i].a;
				}for(int i=n/2+1;i<=n/2+n;i++){
					ans2+=ren[i].a
				}
				cout<<max(ansa,ansb)<<endl;
			}
		}
	}
	
	return 0;
}
