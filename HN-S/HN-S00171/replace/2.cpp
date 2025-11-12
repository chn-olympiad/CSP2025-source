#include<bits/stdc++.h>
using namespace std;
int n=500,q=500,K=3;
vector<pair<string,string>>vec;
mt19937 rng(random_device{}());
uniform_int_distribution<int>gench('a','f'),genlen(0,5),genp(0,K-1);
string genstr(int len=-1){
	string ret;
	if(!~len)
		len=genlen(rng);
	while(len--)
		ret+=gench(rng);
	return ret;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout<<n<<' '<<q<<'\n';
	for(int i=1,x;i<=K;i++){
		x=genlen(rng)+1;
		string s1=genstr(x),s2=genstr(x);
		while(s1==s2)
			s2=genstr(x);
		vec.emplace_back(s1,s2);
	}
	for(int i=1,x;i<=n+q;i++){
		string lp=genstr(),rp=genstr();
		x=genp(rng),cout<<lp<<vec[x].first<<rp<<' '<<lp<<vec[x].second<<rp<<'\n';
	}
	return 0;
}