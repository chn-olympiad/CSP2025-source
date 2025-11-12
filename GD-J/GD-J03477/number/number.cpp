#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll tong[20];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	    if(s[i]>='0'&&s[i]<='9')
	        tong[s[i]-48]++;
	for(int i=9;i>=0;i--){
		while(tong[i]){
		cout<<i;
		tong[i]--;
	    }
	}cout<<endl;
	return 0;
}
