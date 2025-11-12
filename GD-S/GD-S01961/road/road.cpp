#include<bits/stdc++.h>
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
int n,m,k;
bool f[1000001]={0};
	int a[10001]={0};
	int r[1000001][3];
	int o[11][100002];
int dfs(int d,int nn){
	if(d==n)return 0;
	int s=0;
	for(int i=0;i<m;i+=1){
		if(r[i][0]==nn&&f[r[i][1]]==0){
			
				f[r[i][1]]=1;
				s+=r[i][2];
				s+=dfs(d+1,r[i][1]);
			
		}
		else if(r[i][1]==nn){
			if(f[r[i][0]]==0){
				f[r[i][0]]=1;
				s+=r[i][2];
				s+=dfs(d+1,r[i][0]);
			}
		}
	}
	return s;
}
int main(){
fin>>n>>m>>k;f[0]=1;
	for(int i=0;i<m;i+=1){
		fin>>a[0]>>a[1]>>a[2];
	}
	for(int i=0;i<k;i+=1){
		fin>>o[i][n];
		for(int j=0;j<n;j+=1){
			fin>>o[i][j];
		}
	}
	fout<<dfs(1,1);
	return 0;
}

