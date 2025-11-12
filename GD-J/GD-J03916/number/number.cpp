#include<bits/stdc++.h>
using namespace std;
string str;
vector<int> nuber;
bool sortt(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			nuber.push_back(str[i]-'0');
		}
	}
	sort(nuber.begin(),nuber.end(),sortt);
	for(int i:nuber){
		cout<<i;
	}
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
