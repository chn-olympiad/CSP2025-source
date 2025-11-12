#include<bits/stdc++.h>
using namespace std;

#define file
#define infile "polygon.in"
#define outfile "polygon.out"

#ifdef file
#define cin ___cin___
#define cout ___cout___
ifstream ___cin___(infile);
ofstream ___cout___(outfile);
#endif

int n,ans;

vector<int>num;
vector<int>tmp;

void dfs(int step){
	if(step > n){
		if(tmp.size()>=3){
			int cnt = 0,maxx = 0;
			for(int i = 0;i < tmp.size();i++){
				maxx = max(maxx,tmp[i]);
				cnt+=tmp[i];
			}
			if(cnt*2>maxx){
				ans++;
			}
		}
		return;
	}
	tmp.push_back(num[step]);
	dfs(step+1);
	tmp.pop_back();
	dfs(step+1);
}

int main(){
	cin>>n;
	num.resize(n+5,0);
	for(int i = 1;i <= n;i++){
		cin>>num[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

