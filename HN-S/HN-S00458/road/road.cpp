#include<bits/stdc++.h>
using namespace std;
int n,m,k,f;
int ans;
int mmm=1;
struct road{
	int q,z,v;
	bool c;
}a[100000+10000*10+5];
struct side{
	int money;
	int v[10005];
	
}s[15];
void scan(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&a[i].q,&a[i].z,&a[i].v);
	for(int i=1;i<=k;i++){
		scanf("%d",&s[i].money);
		for(int j=1;j<=n;j++)
			scanf("%d",&s[i].v[j]);
	}
}
bool cmp1(road x,road y){
	return x.v<y.v;
}
int min_tree(){
	sort(a+1,a+1+m,cmp1);
	int pd[n+1];
		for(int i=0;i<=n;i++) pd[i]=0;
		for(int i=1;i<=m;i++){
			if(pd[a[i].q]!=pd[a[i].z] || pd[a[i].q]==0 || 0==pd[a[i].z]){
				a[i].c=true;
				ans+=a[i].v;
				if(pd[a[i].q]==0 && 0==pd[a[i].z]) pd[a[i].q]=pd[a[i].z]=mmm++;
				else if(pd[a[i].q]!=0) pd[a[i].z]=pd[a[i].q];//如果是首次接入 
				else if(pd[a[i].z]!=0) pd[a[i].q]=pd[a[i].z];//如果是首次接入 
				else{//将两个连通块相连 
					int gai=a[i].z;
					for(int k=1;k<=n;k++)
						if(a[k].z==gai) a[k].z=a[i].q;
					}
			}
			bool ok=true;int okk=pd[a[i].q];
			for(int i=1;i<=n;i++)
				if(pd[i]!=okk || pd[i]==0) ok=false;
			if(ok)
				break;
		}
		return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scan();
	if(k==0){
		cout<<min_tree();
		return 0;
	}else{
		for(int i=1;i<=k;i++){
			if(s[i].money==0){
				for(int j=1;j<=n;j++){
					a[n+j].q=n+1;
					a[n+j].z=j;
					a[n+j].v=s[i].v[j];
				}
				m+=n;
				n++;
			}
		}
		cout<<min_tree();//
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
