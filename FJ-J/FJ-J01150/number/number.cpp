#include<bits/stdc++.h>
using namespace std;
string s,st="";
int ss,sts;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ss=s.length();
	for(int i=0;i<ss;i++){
		if(s[i]>='0'&&s[i]<='9'){
			st+=s[i];
			sts++;
		}
	}for(int i=sts;i>=0;i--){
		char maxs='0';
		for(int j=0;j<i;j++){
			if(st[j]>maxs) maxs=st[j];
		}for(int j=0;j<i;j++){
			if(st[j]==maxs) {
				swap(st[i-1],st[j]);
				break;
			}
		}
	}cout<<st;
}
