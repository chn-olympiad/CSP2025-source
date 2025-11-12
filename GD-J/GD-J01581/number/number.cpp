#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string s;
vector<int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]>='0' && s[i]<='9')
			a.push_back((int)(s[i]-'0'));
	n=a.size();
	sort(a.begin(),a.end());
	for(int i=n-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
