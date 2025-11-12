#include<bits/stdc++.h>
using namespace std;
const int kMaxn=1e5+10;

int n,m;
int d[4];
int a[kMaxn][4];
long long ans1[10],ans=0;
//priority_queue<pair<int,int>,vector<pair<int ,int>>,less<pair<int,int>> >q;

bool ok[kMaxn];

struct node{
	int va;
	int d;
	int peo;
}s[kMaxn*4];

bool cmp(node x,node y){
	return x.va>y.va;
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	int ttt=1,ijk=1;
	cin>>t;
	
	int nt=t;
	
	while(t--){
		ans=0;
		ijk=1;
		cin>>n;
		d[1]=0;d[2]=0;d[3]=0;
		for(int i=1;i<=n;i++){
			ok[i]=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				s[ijk].d=j;
				s[ijk].peo=i;
				s[ijk].va=a[i][j];
				ijk++;
			}
		}
		ijk--;
		
		sort(s+1,s+1+n*3+10,cmp);
		
		int pos=1;
		while(pos<=ijk+1){
			if(ok[s[pos].peo]==1){
				pos++;
				continue;
			}
			if(d[s[pos].d]>=n/2){
				pos++;
				continue;
			}
			ok[s[pos].peo]=1;
			d[s[pos].d]++;
			ans+=s[pos].va;
			pos++;
		}
		ans1[ttt]=ans;
		ttt++;
	}
	ttt--;
	for(int i=1;i<=ttt;i++){
		cout<<ans1[i]<<'\n';
	}
	
	return 0; 
}
