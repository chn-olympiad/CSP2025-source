#include<bits/stdc++.h>
using namespace std;
string s;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	getline(cin,s);
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			num[(int)s[i]-'0']++;
		}
	}for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			printf("%d",i);
		}
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
