#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,q;
int edge[200005][30][30],sum;
int val[200005];
int nex[200005];
int dep[200005];
void build1(string c1,string c2){
	int a=1;
	for(int i=0;i<(int)c1.size();i++){
		int to1=(int)c1[i]-'a'+1,to2=(int)c2[i]-'a'+1;
		if(edge[a][to1][to2]==0){
			sum++;
			edge[a][to1][to2]=sum;
			dep[sum]=dep[a]+1;
			a=sum;
		}
		else a=edge[a][to1][to2];
		if(i==(int)c1.size()-1) val[a]++;
	}
}
void build2(){
	queue<int> q;
	nex[1]=0;
	for(int i=1;i<=26;i++){
		for(int j=1;j<=26;j++){
			if(edge[1][i][j]>0){
				q.push(edge[1][i][j]);
				nex[edge[1][i][j]]=1;
			}
			else edge[1][i][j]=1;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=1;i<=26;i++){
			for(int j=1;j<=26;j++){
				int y=edge[x][i][j];
				if(y>0){
					q.push(y);
					nex[y]=edge[nex[x]][i][j];
				}
				else edge[x][i][j]=edge[nex[x]][i][j];
				val[y]+=val[nex[y]];
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	sum=1;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		build1(s1,s2);
	}
	build2();
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int a=1,l=-1,f=1;
		for(int i=0;i<(int)t1.size();i++){
			int c1=(int)t1[i]-'a'+1,c2=(int)t2[i]-'a'+1;
			if(c1!=c2) ans=0,f=0;
			else if(f==1) l++;
			a=edge[a][c1][c2];
			if(dep[a]>=i-l) ans+=val[a];
		}
		printf("%d\n",ans);
	}
	return 0;
}

