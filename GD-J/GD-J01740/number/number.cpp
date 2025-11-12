#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>v;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(1*s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		printf("%d",v[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
