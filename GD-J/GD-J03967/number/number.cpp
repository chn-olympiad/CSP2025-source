#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector <int> b;
	int a=s.size();
	int num=0; 
	for(int i=1;i<=a;i++){
		if(s[i]!='a'&& s[i]!='c'&&s[i]!='c'&&s[i]!='d'&&s[i]!='e'&&s[i]!='f'&&s[i]!='g'&&s[i]!='h'&&s[i]!='i'&&s[i]!='j'&&
		s[i]!='k'&&s[i]!='l'&&s[i]!='m'&&s[i]!='n'&&s[i]!='o'&&s[i]!='p'&&s[i]!='q'&&s[i]!='r'&&s[i]!='s'&&s[i]!='t'&&
		s[i]!='u'&&s[i]!='v'&&s[i]!='w'&&s[i]!='x'&&s[i]!='y'&&s[i]!='z'){
			b=b[i];	
			
		} 
	}
	for(int j=1;i<=b.size();j++) cout<<b[i];
	return 0;
}
