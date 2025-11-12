#include<bits/stdc++.h>
using namespace std;
long long nums[1000010],n=0;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			nums[++n]=s[i]-'0';
		}
	}
	sort(nums+1,nums+1+n,cmp);
	for(long long i=1;i<=n;i++){
		cout<<nums[i];
	}
	return 0;
} 
