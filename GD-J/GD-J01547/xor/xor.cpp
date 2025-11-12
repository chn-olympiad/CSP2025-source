#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("ans.txt","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt=0;
	vector<int>v;
	bool s=1;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		v.push_back(x);
		if(x>1) s=0;
	}
	if(s){
		int x=0,y=0;
		for(int i=0;i<n;++i){
			if(v[i]) x++;
			else y++;
		}
		if(k==1){
			cout<<x;
		}
		else cout<<x/2+y;
		return 0;
	} 
	int sum=0;
	for(int i=0;i<n;++i){
		sum^=v[i];
		if(sum==k){
			++cnt;
			sum=0;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
/*
Subtask 1
4 2
2 1 0 3
the ans should be:
2

Subtask 2
4 3
2 1 0 3
the ans should be:
2

Subtask 3
4 0
2 1 0 3
the ans should be:\
1
*/

/*

it hack my greedy!

god!

rp++!!!!!!!!!!

*/
