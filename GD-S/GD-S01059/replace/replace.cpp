#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+10;
string s[N][3],t1,t2;
int n,q,cnt;
int check(string x,string tar,int p){
	int res=0;
	string k=s[p][1];
	for(int i=0;i<x.size();i++){
		if(i+s[p][1].size()-1>=x.size()) break;
		if(x[i]==s[p][1][0]){
			bool flag=true;
			for(int j=i;j<=i+s[p][1].size()-1;j++){
				if(x[j]!=s[p][1][j-i]){
					flag=false;
					break;
				}
			}
			if(flag){
				for(int j=i;j<=i+s[p][1].size()-1;j++){
					x[j]=s[p][2][j-i];
				}
				if(x==tar) res++;
				for(int j=i;j<=i+s[p][1].size()-1;j++){
					x[j]=s[p][1][j-i];
				}
			}
		}
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1>>t2;
		cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=check(t1,t2,i);
		}
		printf("%d\n",cnt);
	}
	return 0;
}
