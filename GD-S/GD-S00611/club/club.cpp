#include<bits/stdc++.h>
int T;
int n;
struct node{
	int i,x,z;
}p[3],k[100010];
std::vector<node> v;
bool flag[100010];
int f[100010];

bool cmp(node x,node y){
	if(x.z>y.z) return true;
	return false;
}

bool cmps(std::pair<int,int> x,std::pair<int,int> y){
	return x.second>y.second;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(flag,0,sizeof(flag));
		memset(f,0,sizeof(f));
		v.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			v.push_back({i,1,a});
			v.push_back({i,2,b});
			v.push_back({i,3,c});
			if(i<=2) p[i]={a,b,c};
		}
		
		if(n<=2){
			int a1=p[1].i,a2=p[1].x,a3=p[1].z;
			int b1=p[2].i,b2=v[2].x,b3=p[2].z;
			printf("%d\n",std::max({a1+b2,a1+b3,a2+b1,a2+b3}));
			continue;
		}
		std::stable_sort(v.begin(),v.end(),cmp);
		int ans=0,sum=0;
		for(auto it:v){
			if(!flag[it.i]&&f[it.x]<n/2){
				ans+=it.z;
				flag[it.i]=1,f[it.x]++;
				sum++;
			}
			if(sum>=n) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
