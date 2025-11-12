#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e6+5;

string s;
int num[10];

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	
	int Lon=s.size();
	for(int i=0;i<Lon;++i){
		if(s[i]>='0' && s[i]<='9')num[ s[i]-'0' ]++;
	}
	
	for(int i=9;i>=0;--i)
	for(int j=0;j<num[i];++j)cout<<i;
	
	return 0;
}