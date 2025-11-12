#include<bits/stdc++.h>
using namespace std;
#define int long long

string s;
int v[10];
vector<int> a;

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
//	scanf("%s",&s);
	ios::sync_with_stdio(0);
	cin>>s;
//	cout<<isxdigit('s'); 
	long long le=s.size(); 
	for(int i=0;i<le;i++){
		if(s[i]>='0' && s[i] <='9'){
			v[(s[i]-'0')]++;
		//	a.push_back();
		}
	} 
	for(int i=9;i>=0;i--){
		while(v[i]--) cout<<i;
	}
	return 0;
}
 
