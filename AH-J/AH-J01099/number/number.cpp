#include<bits/stdc++.h>
using namespace std;
int p[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string S;
	cin>>S;
	for(char c:S){
		if(c>='0'&&c<='9')p[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=p[i];j++){
			cout<<i;
		}
	}
	return 0;
}//wxjwxjwxjwxjwxjwxjwxjwxj
