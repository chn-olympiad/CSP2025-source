#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int k = 0;
int num[MAXN];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w", stdout);
	string s;
	getline(cin,s);
	int len = s.size();
	for(int i = 0;i < len;++i){
		if(isdigit(s[i])){
			num[++k] = s[i] - '0';
		}
	}
	sort(num+1,num+1+k,cmp);
	if(num[1] == 0){
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= k;++i){
		cout << num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
