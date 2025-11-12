#include<bits/stdc++.h>
using namespace std;
string s;
int bj[1000005],sz[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])) /*cout<<"&\n",*/sz[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		//cout<<i<<","<<"*"<<sz[i]<<endl;
		for(int j=1;j<=sz[i];j++) cout<<i;
	}
	fclose(stdin),fclose(stdout);
	return 0;
}