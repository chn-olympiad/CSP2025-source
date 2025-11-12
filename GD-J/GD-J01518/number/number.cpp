#include<bits/stdc++.h>
using namespace std;
char s[1000007];
long long n,i;
vector<long long>v;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(i=0;i<v.size();i++){
		cout<<v[i];
	}
	return 0;
} 
