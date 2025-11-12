#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	vector<int> num;
	for(char c:s){
		if(c>='0'&&c<='9')num.push_back(c-'0');
	}
	sort(num.begin(),num.end(),cmp);
	if(num[0]==0){
		cout<<0;
		return 0;
	}
	for(int n:num)cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
