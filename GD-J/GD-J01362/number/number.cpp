#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
string s;
int n;
vector<int> a;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> s;
	n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a.push_back((int)(s[i]-'0'));
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<int(a.size());i++){
		cout << a[i];
	}
	return 0;
} 
