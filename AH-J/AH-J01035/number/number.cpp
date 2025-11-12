#include<bits/stdc++.h>
using namespace std;//开long long!
int main(){
	freopen("number.in","r",stdin);//注释删掉!
	freopen("number.out","w",stdout);//注释删掉!
	string s,b="";
	long long i,cut=0;
	cin>>s;
	for(i=0;i<(long long)s.size();i++){
		if(isdigit(s[i])){
			b+=s[i];
		}
		if(s[i]=='0'){
			cut++;
		}
	}
	sort(b.begin(),b.end());//才不写函数
	reverse(b.begin(),b.end());//转一下就行
	if((long long)b.size()==cut){
		b="0";
	}
	cout<<b;
	return 0;
}
