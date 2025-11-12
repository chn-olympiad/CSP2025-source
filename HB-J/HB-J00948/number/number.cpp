#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.cpp.in","r",stdin);
	freopen("number.cpp.out","w",stdout);
	string s[110];
	int i=0;
	while(cin>>s[i]){
		i+=1;
		if(i==1){
			cout<<s[i];
			break;
		}
		if(i==2){
			cout<<max(s[i],s[i-1]);
			cout<<min(s[i],s[i-1]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
