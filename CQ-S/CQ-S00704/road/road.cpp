#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct qwe{
	int nx[10020];
	int m;
}s[10020];
int u,v,w;
int tl[10020][10020]; 



int c[15];
bool qc[10025];
 
int a[15][1000020];

int fans;
void dfs(int f,int ans,int en){\
	int anss=ans;
	int ff;
	int enn=en+1;
	qc[f]=1;
	
	if(en>=n){
		if(fans==0){
			fans=ans;
		}else 
		{
		fans=min(fans,ans);
		}
	}
	else 
	{

		for(int i=1;i<=s[f].m;i++){
			anss=ans;
			enn=en+1;
			ff=s[f].nx[i];
			if(qc[ff]==0){
				if(ff>n){
					anss+=c[ff-n];
					enn=en;
				}
				
				anss+=tl[f][ff];
				
				dfs(ff,anss,enn); 
					
				qc[ff]=0;
			}	
		}	
		
		
		
		
	}
	

}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		
		cin>>u>>v>>w;
		tl[u][v]=w;
		tl[v][u]=w;
		s[u].m++;
		s[v].m++;
		s[u].nx[ s[u].m ]=v;
		s[v].nx[ s[v].m ]=u;
		
		
		
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			u=i+n;
			v=j;
			w=a[i][j];
			tl[u][v]=w;
			tl[v][u]=w;
			s[u].m++;
			s[v].m++;
			s[u].nx[ s[u].m ]=v;
			s[v].nx[ s[v].m ]=u;
			
		}
	}
	dfs(1,0,1);
	
	cout<<fans;
	
	return 0;
}


