#include <bits/stdc++.h> 
using namespace std;
int x[100005][3];
long long e[100005];int g[3];int o1,o2,o3,p1,p2,p3;
bool cmp(int a,int b){
	for(int i=0;i<3;i++){
		if(x[a][i]==max(x[a][0],max(x[a][1],x[a][2])))o1=i;
		else if(x[a][i]==min(x[a][0],min(x[a][1],x[a][2])))o3=i;
		else o2=i;
		if(x[b][i]==max(x[b][0],max(x[b][1],x[b][2])))p1=i;
		else if(x[b][i]==min(x[b][0],min(x[b][1],x[b][2])))p3=i;
		else p2=i;
	}return x[a][o1]-x[a][o2]<x[b][p1]-x[b][p2];
}
int main(){
	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;cin>>t;int n;int q1,q2,q3;int minx,m;int a,b;
	for(int i=0;i<t;i++){
		cin>>n;vector<int>f[3];g[0]=0;g[1]=0;g[2]=0;bool z[100005]={0};
		for(int j=1;j<=n;j++){
			for(int k=0;k<3;k++){
				cin>>x[j][k];
			}
		}for(int j=1;j<=n;j++){
			for(int k=0;k<3;k++){
				if(x[j][k]==max(x[j][0],max(x[j][1],x[j][2])))q1=k;
				else if(x[j][k]==min(x[j][0],min(x[j][1],x[j][2])))q3=k;
				else q2=k;
			}e[j]=e[j-1]+x[j][q1];g[q1]++;
				f[q1].push_back(j);}
			for(int r=0;r<3;r++){
				if(g[r]>n/2){
					sort(f[r],f[r]+f[r].size()+1,cmp);
					for(int k=0;k<g[r]-n/2;k++){
						for(int l=0;l<3;l++){
							if(x[f[q1][k]][l]==max(x[f[q1][k]][2],max(x[f[q1][k]][0],x[f[q1][k]][1])))q1=l;
							else if(x[f[q1][k]][l]==min(x[f[q1][k]][2],min(x[f[q1][k]][0],x[f[q1][k]][1])))q3=l;
							else q2=l;
						}
						a=x[f[q1][k]][q2];b=x[f[q1][k]][q3];z[k]=1;e[n]-=x[f[q1][m]][q1]-max(a,b);
					if(a>b){
						g[q2]++;f[q2].push_back(m);
					}else{
						g[q3]++;f[q3].push_back(m);
					}f[q1][k]=-1;
					}break;
				}
			}
			cout<<e[n]<<endl;
		}
	return 0;
}
