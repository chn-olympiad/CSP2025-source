#include<bits/stdc++.h>
using namespace std;
string s[200001][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		int sum=0;
		for(int j=1;j<=n;j++){
			string ss;
			for(int k=0;k<s1.size();k++){
				if(s1[k]==s[j][0][0]){
					ss=s1;
					bool f=0;
					for(int l=1;l<s[j][0].size();l++){
						if(s1[k+l]!=s[j][0][l]){
							f=1;
							break;
						}
					}
					if(!f){
						for(int l=0;l<s[j][0].size();l++){
							ss[k+l]=s[j][1][l];
						}
						if(ss==s2){
							sum++;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
