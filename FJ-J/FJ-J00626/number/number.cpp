#include <bits/stdc++.h>
using namespace std;	
vector<int>v;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	char a;
	while(cin>>a){
		if(a<='9'&&a>='0'){
			v.push_back(a-'0');
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i];
	}
	//#Shang4Shan3Ruo6Shui4
	return 0;
}

