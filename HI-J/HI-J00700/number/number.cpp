#include<bits/stdc++.h>
using namespace std;
string s;
int num[10];
void init(){
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')num[s[i]-'0']++;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	for(int i=9;i>=0;i--)
		while(num[i]){
			cout<<i;
			num[i]--;
		}
	return 0;
}

