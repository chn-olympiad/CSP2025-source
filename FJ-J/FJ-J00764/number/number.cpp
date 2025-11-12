#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string ss;
vector<char> vec;
char s[N];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ss;
	int cnt=0;
	for(long long i=0;i<ss.size();i++){
		if(ss[i]>='0' && ss[i]<='9') vec.push_back(ss[i]);
		cnt++;
	}
	for(int i=0;i<vec.size();i++) s[i]=vec[i];
	sort(s,s+cnt,cmp);
	if(s[0]=='0'){
		cout<<0;
		return 0;
	}
	for(int i=0;i<cnt;i++) cout<<s[i];
	return 0;
}
/*
			ʺ
			ʺ
			ʺ
ʺ			ʺ			ʺ
ʺ			ʺ			ʺ
ʺ			ʺ			ʺ
ʺ			ʺ			ʺ
ʺ			ʺ			ʺ
ʺ			ʺ			ʺ
ʺʺʺʺʺʺʺʺʺʺʺʺʺ
*/
