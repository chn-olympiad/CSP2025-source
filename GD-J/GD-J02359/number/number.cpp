#include<bits/stdc++.h>
using namespace std;
const int WYNN_MAXN_SIZE=1e5+5;
string input;
int cache[WYNN_MAXN_SIZE],cache_top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>input;
	for(int i=0;i<=input.length();i++)
		if('0'<=input[i]&&input[i]<='9')
			cache[++cache_top]=(int)(input[i]-'0');
	sort(cache+1,cache+cache_top+1);
	if(cache[cache_top]==0){	//Wenn die grosser Number ist 0
		cout<<0<<'\n';	//Wir bloss sollen outputen eine 0
		return 0;
	}
	for(int i=cache_top;i>=1;i--)cout<<cache[i];
	cout<<'\n';
	return 0;
} 
