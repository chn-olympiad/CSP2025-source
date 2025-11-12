#include<bits/stdc++.h>
#define D 1010
using namespace std;
int n,q,cnt;
//int trie[][26],end[];
string s1[D],s2[D],t1,t2;
//void ins(string s){
//	int p=0;
//	for(int i=0;i<s.length();i++){
//		int ch=s[i]-'a';
//		trie[p][ch]=++cnt;
//		p=trie[p][ch];
//	}
//	end[p]=true;
//}
//bool find(string s){
//	int p=0;
//	for(int i=0;i<s.length();i++){
//		int ch=s[i]-'a';
//		if()	return false;
//		p=trie[p][ch];
//	}
//	return end[p];
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int j=1;j<=q;j++){
		cnt=0;
		cin>>t1>>t2;
		for(int i=0;i<t1.length();i++){
			for(int j=i;j<=i+4;j++){
				for(int k=1;k<=n;k++){
					string mm=t1.substr(i,j);
					if(mm==s1[k]){
						int cc=0;
						for(int l=i;l<=j;l++){
							t1[l]=s2[k][++cc];
						}
						if(t1==t2){
							cnt++;
						}
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
