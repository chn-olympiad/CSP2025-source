#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	freopen("ans.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>v;
	for(int i=0;i<n*m;++i){
		int x;
		cin>>x;
		v.push_back(x);
	}
	int f=v[0];
	int nx=1,ny=1;
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<n*m;++i){
		if(v[i]==f){
			cout<<ny<<" "<<nx;
			return 0;
		}
		if(nx==n){
			if(ny&1) ++ny;
			else --nx;
		}
		else if(nx==1){
			if(ny&1) ++nx;
			else ++ny;
		}
		else{
			if(ny&1) ++nx;
			else --nx;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Subtask 1

2 2
99 100 97 98

the ans should be:
1 2
*/
/*
Subtask 2

2 2
98 99 100 97

the ans should be:
2 2

Subtask 3

3 3
94 95 96 97 98 99 100 93 92

the ans should be:
3 1

brute:
the sorted arr:100 99 98 97 96 95 94 93 92
the brute_arr:
100 95 94
99 96 93
98 97 952
*/



/*

auto rp++!

*/
