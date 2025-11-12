#include<bits/stdc++.h>
using namespace std;
#define int long long
int limit;
int n;
int anum,bnum,cnum;
int ans=0;
struct node{
	int a,b,c;
}a[100005];
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return (x.b-x.a)>(y.b-y.a);
}
bool ty1,ty2;
void dfs(int x,int num){
	if(x==n+1){
		ans=max(ans,num);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(anum<limit){
			anum++;
			num+=a[x].a;
			dfs(x+1,num);
			num-=a[x].a;
			anum--;
		}
		if(bnum<limit){
			bnum++;
			num+=a[x].b;
			dfs(x+1,num);
			num-=a[x].b;
			bnum--;
		}
		if(cnum<limit){
			cnum++;
			num+=a[x].c;
			dfs(x+1,num);
			num-=a[x].c;
			cnum--;
		}
	}
}
signed main(){
  	freopen("club.in","r",stdin);
  	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ty1=0;ty2=0;
		anum=bnum=cnum=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0){
				ty1=1;
			}
			if(a[i].c!=0){
				ty2=1;
			}
		}
		limit=n/2;
		int sum=0;
		if(ty2==0){
			if(ty1==0){
				sort(a+1,a+n+1,cmp1);
				for(int i=1;i<=limit;i++){
					sum+=a[i].a;
				}
				cout<<sum<<endl;
			}
			else{
				sort(a+1,a+1+n,cmp2);
				for(int i=1;i<=limit;i++){
					sum+=a[i].b;
				}
				for(int i=limit+1;i<=n;i++){
					sum+=a[i].a;
				}
				cout<<sum<<endl;
			}
			continue;
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
