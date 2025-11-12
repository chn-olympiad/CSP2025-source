#include <bits/stdc++.h>
using namespace std;
vector <int> vec;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			vec.push_back(s[i]-'0');
		}
	}//ÅÐ¶ÏÊÇ·ñÎªÊý×Ö£»	
	sort (vec.begin(),vec.end(),cmp);//ÄæÐòÅÅÐò 
	for(int i=0;i<vec.size();i++){
		cout<<vec[i];
	}
	return 0;
} 
//#Shang4Shan3Ruo6Shui4
