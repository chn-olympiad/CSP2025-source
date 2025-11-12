#include<bits/stdc++.h>
using namespace std;
string s;
int sum[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(sum,0,sizeof(sum));
	cin>>s;
	int yxz=s.length();
	for(int i=0;i<yxz;i++){
		if(s[i]>=48&&s[i]<=57){
			sum[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<sum[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
