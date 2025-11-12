#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin)
	//freopen("number.out","w",stdout)
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')
			s[0]++;
		if(s[i]=='1')
			s[1]++;
		if(s[i]=='2')
			s[2]++;
		if(s[i]=='3')
			s[3]++;
		if(s[i]=='4')
			s[4]++;
		if(s[i]=='5')
			s[5]++;
		if(s[i]=='6')
			s[6]++;	
		if(s[i]=='7')
			s[7]++;
		if(s[i]=='8')
			s[8]++;
		if(s[i]=='9')
			s[9]++;
		cout<<s[i];
	}
		
	return 0;
}

