#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
priority_queue<int> a;
string s;

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j;
	cin>>s;
	int len=s.size();
	int ai=0;
	for(i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a.push(s[i]-'0');
			ai++;
		}
	}
	for(i=0;i<ai;i++){
		cout<<a.top();
		a.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 