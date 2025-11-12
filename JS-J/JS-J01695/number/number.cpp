#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

char s[N];
int n;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	vector<int> nums;
	for(int i=1;i<=n;i++) if(isdigit(s[i]))
		nums.push_back(s[i]-'0');
	sort(nums.begin(),nums.end(),greater<int>());
	for(auto x : nums)
		printf("%d",x);
	printf("\n");
	return 0;
}