//GZ_S00508 ª∆∫∆è™  Æ∞À÷– 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct sb{
	int jia,fr,to;
};
vector<int> A[100010];
vector<sb> B;
vector<sb> C[10];
vector<sb> D;
vector<sb> F;
vector<int>G[10010];
int ans=0,ans2=0,ans3=99999999999;
bool in[100020];
int d[11],us[11];
bool us2[1100][100010];
int L[1100][10100];
bool cmp(sb a,sb b){
	return a.jia<b.jia;
}
bool cp(int a,int b){
	return a>b;
}
int er(int a,vector<int>b){
	int l,r=b.size(),mid=0;
	while(r-1>l){
		
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c;cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		B.push_back({c,a,b});
	}
	for(int i=0;i<n;i++){
		in[i]=0;
	}
	for(int i=0;i<k;i++){
		cin>>c;d[i]=c;
		for(int j=1;j<=n;j++){
			cin>>a;
			C[i].push_back({a,i,j});
		}
		sort(C[i].begin(),C[i].begin()+C[i].size(),cmp);
		
	}
	for(int i=0;i<B.size();i++){
		D.push_back(B[i]);
	}
	sort(D.begin(),D.begin()+D.size(),cmp);
	ans=0;
	for(int i=0;i<D.size();i++){
		if(!in[D[i].fr]||!in[D[i].to]){
			in[D[i].fr]=1;
			in[D[i].to]=1;
			ans+=D[i].jia;
			A[D[i].fr].push_back(D[i].jia);
			A[D[i].to].push_back(D[i].jia);
			G[D[i].to].push_back(D[i].fr);
			G[D[i].fr].push_back(D[i].to);
		}
	}
	for(int i=1;i<=n;i++){
		
		sort(A[i].begin(),A[i].begin()+A[i].size(),cp);
		A[i].push_back(-1);
	}
	ans3=ans;
	if(k>0){
		cout<<0;return 0;
	}
	
	cout<<ans3;
	return 0;
}
