#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
};
node a[100010];
int n,t,vis[100010],match[100010],num[100010],vv[1000010][10];
vector<node>v[100010];
bool cmp(node a,node b){
	return a.a>b.a;
}
void hungry(int x){
//	cout <<1;
	for(int i=0;i<3;i++){
		if (num[v[x][i].b]+1<=n/2){
			num[v[x][i].b]++;
			match[x]=v[x][i].b;
			return ;
		}else{
		//	cout <<endl;
		int maxn=0,maxx=-1,maxj; 
			for (int j=1;j<x;j++){
				if (match[j]==v[x][i].b){
					for (int u=0;u<3;u++){
						if (v[j][u].b==v[x][i].b){
							if (u+1<3){
								if(v[j][u+1].a-v[j][u].a+v[x][i].a>maxn){
									maxn=v[j][u+1].a-v[j][u].a+v[x][i].a;
									maxx=u;
									maxj=j;
								}
							}else continue;
						}
					}
				}
			}
			if (maxx!=-1){
				num[v[maxj][maxx+1].b]++;
				match[maxj]=v[maxj][maxx+1].b;
				match[x]=v[x][i].b;
				return ;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		int ans=0,sum1=0,sum2=0,sum3=0;
		cin >>n;
		memset(num,0,sizeof(num));
		memset(match,0,sizeof(match));
		memset(vv,0,sizeof(vv));
		for (int i=1;i<=n;i++){
			int a,b,c;
			cin >>a>>b>>c;
			v[i].clear();
			v[i].push_back({a,1});
			v[i].push_back({b,2});
			v[i].push_back({c,3});
			vv[i][1]=a;
			vv[i][2]=b;
			vv[i][3]=c;
			sort(v[i].begin(),v[i].end(),cmp);
		//	cout <<v[i][0].a<<" "<<v[i][1].a<<" "<<v[i][2].a<<endl;
		}
		for (int i=1;i<=n;i++){
			hungry(i);
		//	for (int j=1;j<=i;j++)cout <<match[j]<<' ';
		//	cout <<endl;
		}
		ans=0;
		for (int i=1;i<=n;i++){
			ans+=vv[i][match[i]];
		}
		cout <<ans<<endl;
	}
	return 0;
} 
