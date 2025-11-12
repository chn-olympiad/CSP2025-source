#include<bits/stdc++.h>
using namespace std;
bool cmp(int xx,int yy){
	return xx>yy;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> a;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			int x=s[i]-'0';
			a.push_back(x);
		}
	}
	sort(a.begin(),a.end(),cmp);
	if(a[0]==0){
		cout<<0;
	}
	else{
		for(int i=0;i<a.size();i++){
			cout<<a[i];
		}
	}
	return 0;
} 
