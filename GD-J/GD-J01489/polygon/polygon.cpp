#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,ans=0;
short a[5005];
vector<int> pick;
vector<int>::iterator it;
bool check(){
	if ((int)pick.size()<3){
		return 0;
	}
	int summ=0,maxx=-1;
	for (int i=0;(long long unsigned)i<pick.size();i++){
		summ+=pick[i];
		maxx=max(pick[i],maxx);
	}
	return summ>2*maxx;
};
void c1(){
	if (ans==998244353){
		ans=0;
	}
};
void dfs(int nidx){
	pick.push_back(a[nidx]);
	if (check()){
		ans++;
		//test
		/*
		cout <<"choose\n";
		*/
		c1();
	}
	//test
	/*
	cout << "#########" << endl;
	for (int i=0;(long long unsigned)i<pick.size();i++){
		cout << pick[i] << endl;
	}
	cout << "#########";
	*/
	for (int i=nidx+1;i<n;i++){
		dfs(i);
	}
	pick.erase(pick.end());
};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for (int i=0;i<n;i++){
		dfs(i);
	}
	
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
