#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

bool cmp(const char &x,const char &y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	cin>>s;
	
	ll len=s.size();
	for(ll i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9') ans+=s[i];
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
}
			
