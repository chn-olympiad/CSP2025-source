#include<bits/stdc++.h>
using namespace std;
string s;
char c;
map<int,int>m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		c=s[i];
		if(c>='0'&&c<='9')
		m[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		int k=m[i];
		for(int j=1;j<=k;j++){
			printf("%d",i);
		}
	}
	return 0;
}
