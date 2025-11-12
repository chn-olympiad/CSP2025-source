#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int >a;
	//0:48 1:49
	
	int tot=0;
	for(int i=0;i<=s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			a.push_back(s[i]);
			tot++;
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<tot;i++){
		cout<<(char)a[i];
	}
	cout<<endl;
	return 0;
}