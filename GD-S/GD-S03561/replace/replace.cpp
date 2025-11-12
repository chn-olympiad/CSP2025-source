#include<bits/stdc++.h>
using namespace std;
int n,q;
pair <string,string> p[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		string str1,str2;
		scanf("%s %s",&str1,&str2);
		make_pair(str1,str2);
	}
	while(q--){
		string s1,s2;
		scanf("%s %s",&s1,&s2);
		if(s1.size()!=s2.size()){
			printf("0");
			continue;
		}
	}
	return 0;
} 
