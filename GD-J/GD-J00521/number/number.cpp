#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
long long siz,nums[10],sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			nums[s[i]-'0']++;
			sum++;
		}
	}
	if(nums[0]==sum){
		printf("%d",0);
		return 0;
	}
	for(int j=9;j>=0;j--){
		for(int i=0;i<=nums[j];i++){
			printf("%d",j);
		}
	}


	return 0;
}

