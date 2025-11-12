#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freoen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sum[s.length()];
	for (int i=0;i<s.length();i++){
		sum[i]=-2;
	}
	for (int i=0;i<s.length();i++){
		if (s[i]<='9' && s[i]>='0'){
			sum[i]=s[i];
			sum[i]-=48;
		}
	}
	sort(sum,sum+s.length(),cmp);
	for (int i=0;i<s.length();i++){
		if (sum[i]<0){
			return 0;
		}
		else{
			cout<<sum[i];
		}
	}
	return 0;
}
