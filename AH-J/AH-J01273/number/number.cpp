#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;	
long long sum[1000005],n;
bool cmp(long long x,long long y){
		return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			sum[n]=s[i]-'0';
		}
	}
	sort(sum+1,sum+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<sum[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
