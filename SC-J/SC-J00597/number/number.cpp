#include<bits/stdc++.h>
//#include<bits/stdc++.h>
using namespace std;
#define ak ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//don't use fclose
//不开ll___
//数组开小直接炸
#define sqrt sqrtl
//#define int long long
inline int randr(int l,int r){return rand()%(r-l+1)+l;}
#define randf(l,r) for(int i=l;i<=r;i=randr(l,r))
signed main(){
	ak;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> num;
	for(auto ch:s)if(isdigit(ch))num.push_back(ch-48);
	sort(num.begin(),num.end());
	reverse(num.begin(),num.end());
	if(num[0]==0){
		cout<<0;
		return 0;
	}
	for(auto i:num)cout<<i;
	
	return 0;
}