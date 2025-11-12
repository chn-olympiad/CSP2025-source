#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=s.size();
	for(int i=0;i<k;i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1+=s[i];
		}
	}
	sort(s1.begin(),s1.end());
	int k1=s1.size();
	for(int i=0;i<k1;i++){
		s2+=s1[(k1-i-1)];
	}
	cout<<s2;
	return 0;
}
