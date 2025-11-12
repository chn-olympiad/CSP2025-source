#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
	int w;
	int id,gai;
};
node v[3000010];
int d[10010],fa[100010],e[3000010];
int cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,len=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[++len].a=x;
		v[len].b=y;
		v[len].w=z;
		v[len].id=0;
	}
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<=n;j++)
			scanf("%d",&d[j]);
		for(int j=1;j<=n;j++){
			v[++len].a=j;
			v[len].b=n+i;
			v[len].w=d[j];
			v[len].id=0;
			e[len]=d[j];
		}
		if(x!=0){
			sort(e+1,e+1+n);
			for(int i=0;i<n;i++){
				if(v[len-i].w<=e[i]+x){
					if(v[len-i].w!=e[i]){
						v[len-i].id=i;
						v[len-i].gai=x;
					}
					else
						v[len-i].id=i+114514;
					v[len-i].w+=x;
					break;
				}
			}
		}
	}
	sort(v+1,v+1+len,cmp);
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	//cout<<n+k-1<<len<<" "<<endl;
	int ans=0,sum=0;
	for(int i=1;i<=len;i++){
		if(ans==n+k-1)
			break;
		if(n<=1000&&m<=100000){
			int f=1;
			for(int i=1;i<=n;i++){
				if(find(i)!=find(i+1))
					f=0;
			}
			if(f)
				break;
		}
		int x=find(v[i].a),y=find(v[i].b);
		if(x!=y){
		//	cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].w<<" "<<sum<<endl;
			if(v[i].id!=0){
				for(int j=i+1;j<=len;j++){
					if(v[i].id-114514==v[j].id){
						v[j].id=0;
						v[j].w-=v[j].gai;
					}
				}
				v[i].id=0;
				sort(v+1,v+1+len,cmp);
			}
			fa[x]=y;
			sum+=v[i].w;
			ans++;
		}
	}
	cout<<sum;
	return 0;
}
