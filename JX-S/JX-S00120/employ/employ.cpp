#include<bits/stdc++.h>
using namespace std;
map<int,string> diff;
map<int ,int> lvv;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,lv;
	string dif;
	cin>>n>>m;
	cin>>dif;
	for(int i=1;i<=n;i++){
		cin>>lv;
		diff[i]=dif[i];
		lvv[i]=lv;
	}
	
	return 0;
}
