#include<bits/stdc++.h>
using namespace std;
const int N=-1;
vector<int>buc(10);
int slove(){
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			buc[s[i]-'0']++;
		}
	}
	string ans="";
	for(int i=9;i>=0;i--){
		while(buc[i]>0){
			char t=i+'0';
			ans=ans+t;
			buc[i]--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	slove();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
