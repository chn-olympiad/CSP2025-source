#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0;
	cin>>s;
	vector<char> p;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
            p.push_back(s[i]);
            cnt++;
		}
	}
    for(int i=0;i<=p.size();i++){
		for(int j=i+1;j<=p.size();j++)
            if(p[j]>p[i]){
                swap(p[i],p[j]);
            }
	}
    for(int i=0;i<=p.size();i++){
		cout<<p[i];
	}
	return 0;
}
