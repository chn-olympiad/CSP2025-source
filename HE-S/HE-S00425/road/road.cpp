#include<bits/stdc++.h>
using namespace std;
struct node{
	int adress;
	int waste;
};
struct Node{
	int ad;//ad为该点在a中的下标 
	vector<node>v;//存孩子 
}a[10021];
int n,m,k;//城市数 边数 村子数 
int num;
bool visit[10021];
long long int ans=INT_MAX;
long long int Max;
int start_;
int tong[50000000];

//void dfs(long long int sum,int adr,int n_){
//	//sum为总价钱 adr为当前节点下标 n_为当前visit了n_点
//	if(n_==n){
//		
//		for(int i=0;i<a[start_].v.size();i++){
//			cout<<sum+a[start_].v[i]<<endl;
//			ans=min(sum+a[start_].v[i].waste,ans);
//		}
//		return;
//	}
//	for(int i=0;i<a[adr].v.size();i++){
//		node tmp=a[adr].v[i];
//		if(visit[tmp.adress]==false){
//			visit[tmp.adress]==true;
//			dfs(sum+tmp.waste,tmp.adress,n_+1);
//			visit[tmp.adress]==false; 
//		}
//	}
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;num=n;
	for(int i=1;i<=m;i++){
		int x,y;//链接x与y
		int w;
		cin>>x>>y>>w;
		tong[w]+=1;
		node tmp;tmp.adress=y;tmp.waste=w;
		a[x].v.push_back(tmp);
		tmp.adress=x;
		a[y].v.push_back(tmp);
	}
	Max=n*(n-1)/2;
	for(int i=1;i<=(1+n)*k;i++){
		int tmp;cin>>tmp;
	}
	int add=0;ans=0;
	while(Max>0){
		while(tong[add]==0)add++;
		Max--;tong[add]--;
		ans+=add;
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<':'<<endl;
//		for(int j=0;j<a[i].v.size();j++){
//			cout<<a[i].v[j].adress<<' '<<a[i].v[j].waste<<endl;
//			
//		}
//		cout<<endl;
//	}
//	long long int ans_1=INT_MAX;
//	for(int i=1;i<=n;i++){
//		start_=i;visit[i]=true;
//		dfs(0,i,1);
//		visit[i]=false;
//		ans_1=min(ans_1,ans);
//		ans=INT_MAX;
//	}
//	
//	//cout<<Max;
//	cout<<ans_1;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
