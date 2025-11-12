#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<long long>numb;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'<10){
			numb.push_back(s[i]-'0');
		}
	}sort(numb.begin(),numb.end(),cmp);
	long long ans=0,jw=1;
	for(int i=0;i<numb.size();i++){
		cout<<numb[i];
		//jw=pow(10,i);
		//ans+=jw*numb[i];
		
	}//cout<<ans; 
	return 0;
}
