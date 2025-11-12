#include<bits/stdc++.h>
using namespace std;
string s;
const int INF=1e6+1;
int num[INF],x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0' && s[i]<='9'){
			num[x]=s[i]-'0';
			x++;
		}
	}sort(num,num+x);
	for(int i=x-1;i>=0;--i){
		printf("%d",num[i]);
	}
	return 0;
}
