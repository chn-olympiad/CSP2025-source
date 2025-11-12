#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll z[N],a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			z[a]=s[i]-'0';
			a++;
		}
	}
	sort(z,z+a);
	for(int i=a-1;i>=0;i--){
		cout<<z[i];
	}
	return 0;
}