#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len = s.size();
	vector<int> a;
	for(int i = 0;i < len;++i){
		if(s[i] >= '0' && s[i] <= '9'){a.push_back(s[i] - '0');}
		}
	
	sort(a.begin(),a.end());
	
	len = a.size();
	do{
		len--;
		cout << a[len];
	}while(len);
	return 0;
}
