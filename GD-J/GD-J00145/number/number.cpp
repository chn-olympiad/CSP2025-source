//Forza Ferrari!
#include<iostream>
#include<algorithm>
using namespace std;
int nums[1000001];
string s;
// long long ans=0;
long long coun1t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	
	for(long long i=0;i<s.size();i++){
		if(isdigit(s[i])){
			nums[coun1t++]=int(int(s[i])-48);
			// count++;
		}
	}
	sort(nums,nums+coun1t,greater<int >());
	for(long long i=0;i<coun1t;i++){
		cout<<nums[i];
	}
	return 0;
}
