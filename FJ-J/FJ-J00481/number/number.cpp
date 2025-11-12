#include<bits/stdc++.h>
using namespace std;
string s;
const int N=8e8+5;
struct stu{
	char a;
}b[N];
bool cmp(stu a,stu b){
	return a.a>b.a;
}
int main(){
	freopen("number","w",stdin);
	freopen("number","r",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		b[i].a=s[i]-'0';
	}
	sort(b,b+s.size(),cmp);
	for(int i=0;i<s.size();i++){
		if(b[i].a>9||b[i].a<0) continue; 
		cout<<int(b[i].a);
	}
	return 0;
}
