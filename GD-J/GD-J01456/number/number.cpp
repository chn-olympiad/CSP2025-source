#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int N=1e6+5;
string s,ans;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s){
		if(isdigit(i)){
			ans+=i;
		}
	}
	sort(ans.begin(),ans.end(),greater<char>());
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

