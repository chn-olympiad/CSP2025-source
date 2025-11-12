#include<bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
//const int N=1e5;
int tong[100];
string s;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0' and s[i]<='9'){
    		tong[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tong[i];j++){
			cout<<i;
		}
	}
    return 0;
}