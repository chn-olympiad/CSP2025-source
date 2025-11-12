#include <bits/stdc++.h>
using namespace std;
#define rt return
typedef long long ll;
string s; 
vector<int> v;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=(int)s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	for(auto y:v){
		printf("%d",y);
	}puts("");
	rt 0;	
} 
