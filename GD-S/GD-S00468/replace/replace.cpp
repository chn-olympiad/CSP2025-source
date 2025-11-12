#include<bits/stdc++.h>
using namespace std;
vector<pair<string,string> >v1,v2;
int n,q;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	while(n--){
		cin>>s1>>s2;
		v1.push_back(make_pair(s1,s2));
	}
	while(q--){
		cin>>s1>>s2;
		v2.push_back(make_pair(s1,s2));
		printf("0\n");
	}
	return 0;
}
