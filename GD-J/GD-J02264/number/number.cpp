#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
bool cmp(int a, int b){
	return a>=b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]);
		}
	} 
	sort(v.begin(), v.end(), cmp);
	for(int i:v){
		cout<<(char)i;
	}
	return 0;
} 
