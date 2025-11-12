#include<bits/stdc++.h>
using namespace std;
int bigNum(string s){
	int n=s.size();
	vector<int> vec;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			vec.push_back(s[i]-'0');
		}
	}
	sort(vec.begin(),vec.end());
	int sum=0;
	for(int j=vec.size()-1;j>=0;j--){
		sum=sum*10+vec[j];
	}
	return sum;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	cout<<bigNum(s);
	return 0;
} 
