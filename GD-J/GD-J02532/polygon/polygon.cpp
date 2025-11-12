#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool use[5005];
vector<string> paths;
int n;
void dfs(string path){
	
	if(path.size()>n){
		path=""; 
		return ;
	}
	int maxn=-1,sumn=0;
	for(int i=0;i<path.size();i++){
		maxn=(maxn,path[i]-'0');
		sumn+=path[i]-'0';
	}
	if(sumn>maxn*2){
		paths.push_back(path);
	}
	for(int i=0;i<n;i++){
		if(!use[i]){
			path+=char(a[i]+'0');
			use[i]=true;
			dfs(path);
			use[i]=false;
		}
	}
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	string t="";
	dfs(t);
	for(int i=0;i<paths.size();i++){
		cout << paths[i] << endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
