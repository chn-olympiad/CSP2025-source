#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
vector<int>ve;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ve.push_back(s[i]-'0');
		}
	}
	sort(ve.begin(),ve.end(),cmp);
	for(auto c:ve)cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
