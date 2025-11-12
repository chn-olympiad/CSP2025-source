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
	getline(cin,s);
	for(int i=0;i<=int(s.size())-1;i++){
		if(s[i]>='0'&&s[i]<='9') v.push_back(s[i]-'0');
	}
	sort(v.begin(),v.end(),cmp);
	if(v[0]==0) printf("0");
	else{
		for(int i=0;i<=int(v.size())-1;i++){
			printf("%d",v[i]);
		}
	}
	return 0;
}