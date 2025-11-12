#include<bits/stdc++.h>

using namespace std;
int p[10010];
struct edge{
	int x;int y;long long z;
};
edge e[1000010];
int find(int x){
	if(p[x]!=x){
		p[x]=find(p[x]);
	}
	return p[x];
}
bool cmp(edge a1,edge a2){
	if(a1.z<a2.z){
		return true;
	}else{
		return false;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;int m;int k;
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			p[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>e[i].x>>e[i].y>>e[i].z;
		}	
		sort(e+1,e+m+1,cmp);int num=n-1;long long sum=0;
		for(int i=1;i<=m;i++){
			int a=find(e[i].x);int b=find(e[i].y);
			if(a!=b){
				p[a]=b;
				sum+=e[i].z;
				num--;
				if(num==0){
					cout<<sum;
					break;
				}
			}
		}
	}else{
		cout<<0;
	}
	
	return 0;
}