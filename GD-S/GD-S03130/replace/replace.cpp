#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<map>
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;
const int N=1e6+5;
map< string,int > mp1,mp2;
string t1,t2,s;
int n,q;
string substr(string a,int be,int ed){
	string b;
	for(int i=be;i<=ed;i++){
		b+=a[i];
	}
	return b;
}
int check(int be,int ed,int len){
	int flag=0;
	if(be>0){
		if(substr(t1,0,be-1)!=substr(t2,0,be-1)) flag=1;
	}
	if(ed<len-1){
		if(substr(t1,ed+1,len-1)!=substr(t2,ed+1,len-1)) flag=1;
	}
	return flag;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s;mp1[s]=i;
		cin>>s;mp2[s]=i;
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int len=t1.size(),ans=0;
		int len1=t2.size();
		if(len!=len1){
			printf("0\n");continue;
		}
		string sud1,sud2;
		for(int j=0;j<len;j++){
			for(int r=0;r<=j;r++){
				if(check(r,j,len)) continue;
				sud1=substr(t1,r,j);
				sud2=substr(t2,r,j);
				if(mp1[sud1]==mp2[sud2]&&mp1[sud1]){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
