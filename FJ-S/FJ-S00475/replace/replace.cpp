#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
string str1[maxn],str2[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str1[i]>>str2[i];
	}
	for(int i=1;i<=q;i++){
		int cnt=0;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<"0\n";
			continue;
		}
		for(int j=1;j<=n;j++){
			if(s1.length()<str1[j].length()) continue;
			for(int k=0;k<=s1.length()-str1[j].length();k++){
				int flag=1;
				for(int l=0;l<str1[j].length();l++){
					if(s1[k+l]!=str1[j][l]){
						flag=0;
						break;
					}
				}
				if(flag){
					string tmp=s1;
					for(int l=0;l<str1[j].length();l++){
						tmp[k+l]=str2[j][l];
					}
					for(int l=0;l<s1.length();l++){
						if(tmp[l]!=s2[l]){
							flag=0;
							break;
						}
					}
				}
				if(flag) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
