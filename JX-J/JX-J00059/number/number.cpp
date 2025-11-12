#include<bits/stdc++.h>
#include<string>
using namespace std;
vector<int> x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[100]={0};
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]-'0'<10) a[s[i]-'0']++;
		}
	for(int i=10;i>=0;i--){
		while(a[i]!=0){
			x.push_back(i);
			a[i]--;
			}
		}
	int v=x.size();
	for(int i=0;i<v;i++){
		cout<<x[i];
		}
	return 0;
}
