#include<bits/stdc++.h>
using namespace std;
int n,q,sum;
struct node{
	string S1,S2;
}f[5000010];
string s1,s2;
int check(string SS){
	for(int i=1;i<=n;i++)if(SS==f[i].S1)return i;
	return 0;
}
void serch(string noww){
	if(noww==s2&&noww!=s1){
		sum++;
		return;
	}
	string x="";
	for(int i=0;i<noww.size();i++){
		if(i>0)x+=noww[i-1];
	    string New="",z="";
		for(int j=i;j<noww.size();j++){
			New+=noww[j];
			int C=check(New);
			if(C!=0){
				for(int k=j+1;k<noww.size();k++)z+=noww[k];
				serch(x+f[C].S2+z);
			}
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>f[i].S1>>f[i].S2;
	while(q--){
		sum=0;
		cin>>s1>>s2;
		serch(s1);
		cout<<sum<<endl;
	}
	return 0;
}

