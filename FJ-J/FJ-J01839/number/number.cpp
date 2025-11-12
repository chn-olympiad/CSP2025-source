#include<iostream>
#include<cstring>
using namespace std;
int cnt[15],n;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0')cnt[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++)cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//8:42 finished,qi wang de fen 100pts. 
