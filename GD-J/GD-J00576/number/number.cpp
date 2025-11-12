#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100;
int a[N];
string s;

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
}
