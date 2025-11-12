#include <bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
	int lens1,lens2;
};
node s[200005];
int n,m;
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	char c;
	c=getchar();
	for(int i=1;i<=n;i++){
		
		int idx=0;
		c=getchar();
		while(c!='\n'&&c!='\0'&&c!=' '&&c!=EOF){
			s[i].s1+=c;
			idx++;
			c=getchar();
		}
		s[i].s1[idx]='\0';
		s[i].lens1=idx;
		
		idx=0;
		c=getchar();
		while(c!='\n'&&c!='\0'&&c!=' '&&c!=EOF){
			s[i].s2+=c;
			idx++;
			c=getchar();
		}
		s[i].s2[idx]='\0';
		s[i].lens2=idx;
	}
	
	
	for(int i=1;i<=m;i++){
		string a1,a2;
		int lena1,lena2;
		
		int idx=0;
		c=getchar();
		while(c!='\n'&&c!='\0'&&c!=' '&&c!=EOF){
			a1+=c;
			idx++;
			c=getchar();
		}
		a1[idx]='\0';
		lena1=idx;
		
		idx=0;
		c=getchar();
		while(c!='\n'&&c!='\0'&&c!=' '&&c!=EOF){
			a2+=c;
			idx++;
			c=getchar();
		}
		a2[idx]='\0';
		lena2=idx;
		
		int count1=0;
		for(int j=1;j<=n;j++){
			string a5=a1; 
			if(lena1<s[j].lens1)continue;
			int idx1=a1.find(s[j].s1);
			if(idx1==-1)continue;
			for(int k=idx1;k<=s[j].lens1+idx1-1;k++){
				a5[k]=s[j].s2[k-idx1];
			}
			if(a5==a2)count1++;
		}
		cout<<count1<<'\n'; 
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

2 1
xabcx xadex
bc de
xabcx xadex

4 1
a b
aa bb
aaa bbb
aaaa bbbb
aabbc bbbbc

4 2
xabcx xadex
bc de
abc ade
cx ex
xabcx xadex
cxx exx

2 1
aa bb
ad ce
a b
*/