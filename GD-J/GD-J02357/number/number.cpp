#include<iostream>
#include<queue> 
#include<algorithm>
using namespace std;
priority_queue<char> s;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a;
	for(int i=0;i<a.size();i++) if(a[i]>='0'&&a[i]<='9') s.push(a[i]);
	while(!s.empty()) cout<<s.top(),s.pop();
} 
