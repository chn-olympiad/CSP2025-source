#include<bits/stdc++.h>


// bfs+jianzhi
using namespace std;
using ll=long long;

int n;
ll result=0;
const int MAXN =10000;
vector<int> path;
bool np[MAXN];
//vector<vector<vector<int>>> ys;  // ceng-path-int(sort)
vector<vector<int>> ys[MAXN];
int a[MAXN];

void ts(){
//	cout<<"ts"<<endl;
//	for(int i:path)cout<<i<<" ";
//	cout<<endl;
}

void ts2(int k){
//	cout<<"ts2"<<endl;
//	for(int u=0;u<ys[k].size();u++){for(int i:ys[k][u])cout<<i<<" ";cout<<endl;}
//	cout<<endl;
}

void init_ys(){
	for(int i=0; i<n; i++){
		vector<vector<int>> t;
		ys[i]=t;
	}
}

void path_exist(){
	if(path.empty())return;
	if(path.size()==1)return;
	int max_li=0, sum_l=0;
	for(int i:path){
		sum_l+=a[i];
		if(max_li<a[i])max_li=a[i];
	}
	if (sum_l>2*max_li)result+=1;
//	ts();
//	cout<<"exist func call"<<setw(4)<<result<<endl;
}

void jianzhi_add(){
	if(path.empty())return;
	if(path.size()<=1)return;
	vector<int> jz_path = path;
	sort(jz_path.begin(),jz_path.end());
	ys[path.size()].push_back(jz_path);
//	ts2(path.size());
	return;
}

bool jianzhi_exist(){
	if(path.empty())return false;
	if(path.size()<=1)return false;
	if(ys[path.size()].empty())return false;
	vector<int> ju_path = path;
	sort(ju_path.begin(),ju_path.end());
	bool flag=true;
	for(int i=0; i<ys[path.size()].size(); i++){
		flag=true;
		for(int t=0;t<ys[path.size()][i].size();t++){
//			ts2(path.size());	
			if(ju_path[t]!=ys[path.size()][i][t])flag=false;
		}
		if(flag)return true;
	}
	return false;
}

bool path_num_e(int u){
	if(path.empty())return false;
	for(int i:path){if(u==i)return true;}
	return false;
}

void npv(){
	bool flag=true;
	while(flag){
	flag=false;
	int max_a=0, max_index=-1, sum_l=0;
	for(int i=0; i<n; i++){
		if(np[i])continue;
		sum_l+=a[i];
		if(max_a<a[i]){max_a=a[i];max_index=i;}
	}
	sum_l-=max_a;
	if(sum_l<=max_a){
		np[max_index]=true;
		flag=true;
	}
	}
}



void dfs(){
	if(!path.empty()){
		if(path.size()==n){
		return;
	}
	}
	for(int i=0;i<n;i++){
		if(path_num_e(i))continue;
		if(np[i])continue;
		path.push_back(i);
//		ts();
//		if(jianzhi_exist()){cout<<"jian"<<endl;path.pop_back();continue;}
		if(jianzhi_exist()){path.pop_back();continue;}
		dfs();
		jianzhi_add();
		path_exist();
		path.pop_back();
	}
}



int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for(int i=0; i<n ;i++){
		cin >> a[i];
	}
	init_ys();
	npv();
	dfs();
	cout<<((result%998)%244)%353;
	return 0;
}

