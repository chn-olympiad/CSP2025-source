#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
string s1[200005],s2[200005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=m;i++){
		cin>>t1>>t2;
		sum=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k+s1[j].size()-1<t1.size();k++){
				string s=t1.substr(k,s1[j].size());
				if(s==s1[j]){
					string b="";
					for(int l=0;l<k;l++)
						b+=t1[l];
					b+=s2[j];
					for(int l=k+s1[j].size();l<t1.size();l++)
						b+=t1[l];
					if(b==t2) sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
} 
