#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
string a;
vector<int>s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			s.push_back(a[i]-'0');
		}
	}
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<s.size();i++){
		printf("%d",s[i]);
	}
	return 0;
}
