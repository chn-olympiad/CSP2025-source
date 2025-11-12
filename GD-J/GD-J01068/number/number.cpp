#include<bits/stdc++.h>
using namespace std;
string a;
vector<long long>ans;
bool cmp(long long a, long long b){
	return a > b;
}
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a ;
	long long len = a.size();
	for(int i = 0; i < len; i++){
		if(a[i]=='0')ans.push_back(0);
		else if(a[i]=='1')ans.push_back(1);
		else if(a[i]=='2')ans.push_back(2);
		else if(a[i]=='3')ans.push_back(3);
		else if(a[i]=='4')ans.push_back(4);
		else if(a[i]=='5')ans.push_back(5);
		else if(a[i]=='6')ans.push_back(6);
		else if(a[i]=='7')ans.push_back(7);
		else if(a[i]=='8')ans.push_back(8);
		else if(a[i]=='9')ans.push_back(9);
	}
	cout << endl; 
	sort(ans.begin(),ans.end(),cmp);
	for(int i = 0; i < (long long)ans.size(); i++){
		cout << ans[i];
	}
	return 0;
} 
