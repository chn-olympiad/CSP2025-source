#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int N=1e5+5;
string str;
vector<int> nums;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(char ch:str){
		if('0'<=ch&&ch<='9')
			nums.push_back(ch-'0');
	}
	sort(nums.begin(),nums.end(),greater<int>());
	for(int a:nums)
		cout<<a;
	return 0;
}
