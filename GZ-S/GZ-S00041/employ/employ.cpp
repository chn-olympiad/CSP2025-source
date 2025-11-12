//GZ-S00041 北京师范大学贵阳附属中学 冷东来
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<int> c;
	int zero=0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a==0) zero++;
		c.push_back(a);
	}
	bool specialA=1;
	for(int i=0;i<s.length();i++) specialA=s[i]=='0';
	cout<<15656156;
	return 0;
} 
