#include<bits/stdc++.h>
using namespace std;
string s;
int s1[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int z=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			s1[z]=int(s[i]-48);
			z++;
		}
	}
	for(int i=0;i<z;i++)for(int j=i;j<z;j++)if(s1[j]>s1[i])swap(s1[j],s1[i]);
	for(int i=0;i<z;i++)cout<<s1[i];
	return 0;
}
