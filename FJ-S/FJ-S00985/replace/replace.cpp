#include<bits/stdc++.h>
using namespace std;
string as[200005],bs[200005],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>as[i]>>bs[i];
	while(q--){
		long long ans=0;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<"0\n";
			continue;
		}for(int i=1;i<=n;i++){
			if(s1.length()<as[i].length())continue;
			int t=s1.length()-as[i].length()+1,tt=as[i].length();
			for(int j=0;j<t;j++){
				int f=1;
				string s=s1;
				for(int k=j;k<j+tt;k++){
					if(s1[k]!=as[i][k-j]){
						f=0;
						break;
					}s[k]=bs[i][k-j];
				}if(!f)continue;
				if(s==s2)ans++;
			}
		}cout<<ans<<endl;
	}
	return 0;
} 
