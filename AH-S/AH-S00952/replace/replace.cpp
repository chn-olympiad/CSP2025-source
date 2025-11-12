#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1[200010],s2[200010],s3[200010],s4[200010];
int A[200010];
string a1,a2,b1,b2;
int c1,c2,sum;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].length();j++){
			if(s1[i][j]!=s2[i][j]){
				A[i]=j;
				break;
			}
		}
		for(int j=0;j<s1[i].length();j++){
			if(s1[i][j]!=s2[i][j]){
				s3[i]+=s1[i][j];
				s4[i]+=s2[i][j];
			}
		}
	}
	while(m--){
		b1="";
		b2="";
		c1=-1;
		c2=-1;
		sum=0;
		cin>>a1>>a2;
		if(a1.length()!=a2.length()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<a1.length();i++){
			if(a1[i]!=a2[i]){
				c1=i;
				break;
			}
		}
		for(int i=0;i<a1.length();i++){
			if(a1[i]!=a2[i]){
				b1+=a1[i];
				b2+=a2[i];
				c2=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(s3[i]==b1&&s4[i]==b2){
				int t=0,k=0;
				int v=s1[i].length();
				for(int j=c1-A[i];j<c1+v-A[i];j++){
					if(a1[j]==s1[i][t]&&a2[j]==s2[i][t]){
						k++;
					}
					t++;
				}
				if(k==s1[i].size())sum++;
			}
		}
		cout<<sum<<endl;
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
 */
