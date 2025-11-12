#include<bits/stdc++.h>
using namespace std;
string t1,t2,s[10001][2];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		int ss=0;
		cin>>t1>>t2;
		string t3=t1;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			int s1=1,k=0;
			if(t1.size()<s[j][0].size())continue;
			while(k<t1.size()&&t1[k]!=s[j][0][0])k++;
			int k1=k;
			if(k>=t1.size())s1=0;
			while(k<t1.size()&&k-k1<s[j][0].size()){
				if(t1[k]!=s[j][0][k-k1]){
					s1=0;
					break;
				}
				t1[k]=s[j][1][k-k1];
				k++;
			}
			ss+=s1&(t1==t2);
			t1=t3;
		}
		cout<<ss<<endl;
	}
	return 0;
} 

