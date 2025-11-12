//number 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
long long n,v[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=strlen(s);
	for(int i=0;i<=n-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=v[i];j++){
			cout<<i;
		}
		//cout<<v[i]<<endl;
	}
	return 0;
}
