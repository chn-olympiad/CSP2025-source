#include<iostream> 
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> m;
	int sizes=0;
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			m.push_back(s[i]-'0');
			sizes++;
		}
	}
	sort(m.begin(),m.end());
	if(m[0]==0){
		cout<<0;
		return 0;
	}
	while(sizes--){
		cout<<m[sizes];
	}
	return 0;
}
