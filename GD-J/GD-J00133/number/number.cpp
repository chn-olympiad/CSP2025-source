#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;int c=0,m=s.size();
	vector<int>n(m+1);
	for(int i=0;i<m;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[c++]=s[i]-'0';
		}
	}sort(n.begin(),n.end(),greater<int>());
	for(int i=0;i<c;i++){
		printf("%d",n[i]);
	}return 0;
	fclose(stdin);
	fclose(stdout);
}
