#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sz=s.size();
	for(int i=0;i<sz;i++){
		if(s[i]<='9' && s[i]>='0') v.push_back(s[i]-'0');
	}sort(v.begin(),v.end(),cmp);
	if(v[0]==0) cout<<0;
	else{
		int vz=v.size();
		for(int i=0;i<vz;i++) cout<<v[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
