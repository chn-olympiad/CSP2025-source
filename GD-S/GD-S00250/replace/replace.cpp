#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int n,q;
string s1[N],s2[N],t1[N],t2[N];
int s1b[N],s2b[N];
int main(){
	freopen("replace4.in","r",stdin);
	freopen("replace.out","w",stdout); 
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s %s",s1[i],s2[i]);
		for(int j=0;j<s1[i].length();j++){
			if(s1[i][j]=='b') s1b[i]=j;
			if(s2[i][j]=='b') s2b[i]=j;
			if(s1b[i]&&s2b[i]) break;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%s %s",t1[i],t2[i]);
		if(t1[i].length()!=t2[i].length()){
			printf("0");
			continue;
		}
		int t1b,t2b;
		for(int j=0;j<=t1[i].length();j++){
			if(t1[i][j]=='b'){
				t1b=j;
				break;
			}
		}
		for(int j=0;j<=t2[i].length();j++){
			if(t2[i][j]=='b'){
				t2b=j;
				break;
			}
		}
		int sum=0;
		for(int j=1;j<=n;j++){
			if((t1b-t2b)==(s1b[j]-s2b[j])) sum++;
		}
	}
	return 0;
}
/*
t1 t2不等长 0

浪费600块 
*/
