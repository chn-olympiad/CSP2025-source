#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int>a;
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a.push_back(s[i]-'0');
		}
	}sort(a.begin(),a.end(),cmp);
	int len2=a.size();
	for(int i=0;i<len2;i++){
		cout<<a[i];
	}fclose(stdin);
	fclose(stdout);
	return 0;
}

