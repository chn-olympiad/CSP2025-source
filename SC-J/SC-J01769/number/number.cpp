#include<bits/stdc++.h>
using namespace std;
vector<int> P;
string a;
bool cmp(int x,int y){return x>y;}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.length();
	for(int i=0;i<len;i++) if('0'<=a[i] and a[i]<='9') P.push_back(int(a[i]-'0'));
	sort(begin(P),end(P),cmp);
	for(int p:P) cout<<p;
	return 0;
}