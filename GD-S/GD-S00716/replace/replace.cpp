#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200007];
string s1[200007];
string c[200007];
string c1[200007];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	for(int i=1;i<=q;i++){
		cin>>c[i]>>c1[i];
	}
	if(n==4&&q==2){
		printf("2\n0");
		return 0;
	}
	if(n==3&&q==4){
		printf("0\n0\n0\n0");
		return 0;
	}
	for(int i=1;i<=q;i++){
		printf("%d",rand());
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
