#include<bits/stdc++.h>
using namespace std;
int n,buf;
vector<int>a;
vector<bool> chosen;
set<unsigned long long> ways;
void dfs(int level=0,int chosennum=0){
	int summ=0,maxx=-1;
	for(int i=0;i<n;i++){
		if(chosen[i]){
			summ+=a[i];
			maxx=max(maxx,a[i]);
		}
	}
	if(summ>maxx*2 && chosennum>2){
		unsigned long long a=0;
		for(bool i:chosen){
			a*=2;
			if(i) a+=1;
		}
		ways.insert(a);
	}
	if(level==n) return;
	chosen[level]=true;
	chosennum++;
	dfs(level+1,chosennum);
	chosennum--;
	chosen[level]=false;
	dfs(level+1,chosennum);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a.resize(n);
	chosen.resize(n);
	for(int i=0;i<n;i++){
		cin>>buf;
		a[i]=buf;
		chosen[i]=false;
	}
	dfs();
	cout<<ways.size();
	fclose(stdout);
	fclose(stdin);
	return 0;
}
