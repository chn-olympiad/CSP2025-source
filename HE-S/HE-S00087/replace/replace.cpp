#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string s1[n],s2[n],t1[q],t2[q];
	string t[q];
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		ans=0;
		cin>>t1[i]>>t2[i];
		for(int j=0;j<n;j++){
			for(int k=0;k<=t1[i].length()-s1[i].length();k++){
				for(int l=0;l<k;l++){
					t[i][l]=t1[i][l];
				}
				for(int l=0;l<s1[i].length();l++){
					t[i][k+l]=s1[j][k+l];
				}
				for(int l=0;l<t1[i].length();l++){
					t[i][s1[j].length()+l]=t1[i][s1[j].length()+l];
				}
				if(t[i]!=t1[i]) continue;
				for(int l=0;l<s1[j].length();l++){
					t[i][k+l]=s2[j][k+l];
				}
				if(t[i]==t2[i]) ans++; 
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
