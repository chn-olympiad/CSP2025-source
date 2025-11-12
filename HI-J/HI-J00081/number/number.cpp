#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int max=0;
	for(int i=1;i<=s.size();i++){
		if(i>='0'&&i<='9'){
			max++;
		}
		else{
			i=-1;
		}
	} 
	cout<<s;
	
	fclose(stdin);fclose(stdout);
} 
