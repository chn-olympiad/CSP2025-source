#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long sum[10]={0,0,0,0,0,0,0,0,0,0};
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') {
			sum[int(s[i])-48]++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=sum[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
} 
