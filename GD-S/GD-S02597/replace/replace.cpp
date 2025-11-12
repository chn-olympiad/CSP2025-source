#include<iostream>
#include<utility>
#include<map>
using namespace std;

struct Node{
	string a,b;
}a[200100];
map<string,string> m;

pair<int,int> check(string s1,string s2){
	int n = s1.size(),id1,id2;
	for(int i = 0; i < n; i++){
		if(s1[i] != s2[i]){
			id1 = i;
		}
	}
	for(int i = n-1; i > 0; i--){
		if(s1[i] != s2[i]){
			id2 = i;
		}
	}
	return {id1,id2};
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,mx=0,t,c;
	string s1,s2;
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>s1>>s2;
		a[i] = {s1,s2};
		mx = max(mx,(int)s1.size());
		m[s1] = s2;
	}
	while(q--){
		cin>>s1>>s2;
		if(s1.size() != s2.size()){
			cout<<0<<'\n';
			continue;
		}
		auto __RP_plus_plus__S_200pts__ = check(s1,s2);
		t = __RP_plus_plus__S_200pts__.second-__RP_plus_plus__S_200pts__.first+1;
		if(t > mx){
			cout<<0<<'\n';
			continue;
		}
		c = 0;
		for(int i = 0; i < s1.size(); i++){
			for(int j = 1; j <= n; j++){
				if(i+a[j].a.size()>s1.size() || s1.substr(i,a[j].a.size())!=a[j].a){
					continue;
				}
				c += s1.substr(0,i)+a[j].b+s1.substr(i+a[j].a.size())==s2;
			}
		}
		cout<<c<<'\n';
	}
	return 0;
}