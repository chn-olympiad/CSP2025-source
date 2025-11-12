#include<iostream>
#include<cstring>
using namespace std;
const int N=2e5+5,L=5e6+5;
int n,q;
int l1;
string s[N][2],t1,t2;
string st[L],en[L];//表示t1的前后缀 
int nxt[L];
int ans;
void prep(string str){
	int len=str.size()-1;
	for(int i=2,j=0;i<=len;i++){
		while(j&&str[i]!=str[j+1]) j=nxt[j];
		if(str[i]==str[j+1]) j++;
		nxt[i]=j;
	}
}
void KMP(string sb,string sa,string str){
	int la=sa.size()-1,lb=sb.size()-1;
	for(int i=1,j=0;i<=la;i++){
		while(j&&sa[i]!=sb[j+1]) j=nxt[j];
		if(sa[i]==sb[j+1]) j++;
		if(j==lb){//完成匹配 
			if(st[i-j]+str+en[i+1]==t2) ans++;//判断这次更改是否可以 
			j=nxt[j];
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		s[i][0]='#'+s[i][0];
		s[i][1]=s[i][1];
	}
	while(q--){
		cin>>t1>>t2;
		l1=t1.size();
		t1='#'+t1;
		t2='#'+t2;
		st[0]="#";
		en[l1+1]="";
		for(int i=1;i<=l1;i++) st[i]=st[i-1]+t1[i];
		for(int i=l1;i>=1;i--) en[i]=t1[i]+en[i+1];
		ans=0;
		for(int i=1;i<=n;i++){//KMP直接暴力枚举 
			prep(s[i][0]);
			KMP(s[i][0],t1,s[i][1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
