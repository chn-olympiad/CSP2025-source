#include<bits/stdc++.h>
using namespace std;
vector<int> nums;
string s;
bool cmp(int a,int b) {
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>s;
	for(char i:s) {
		if ('0'<=i && '9'>=i) {
			nums.push_back(i-'0');
		}
	}
	sort(nums.begin(),nums.end(),cmp);
	for(int i:nums) cout<<i;
}
