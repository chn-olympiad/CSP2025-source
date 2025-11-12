#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int b[n],b1[n],ls;
	string s[n],s1[n],a,a1;
	for(int i=0;i<n;i++){
		cin>>s[i]>>s1[i];
		ls=s[i].length();
		for(int j=0;j<ls;j++){
			if(s[i][j]=='b') b[i]=j;
			if(s1[i][j]=='b') b1[i]=j;
			if(b[i] && b1[i]) break;
		}
	}
	for(int i=0;i<q;i++){
		cin>>a>>a1;
		int la=a.length(),lb=0,lb1=0,ans=0;
		for(int j=0;j<la;j++){
			if(a[j]=='b'){
				lb=j;
			}if(a1[j]=='b') lb1=j;
			if(lb&&lb1) break;
		}
		for(int j=0;j<n;j++) if(lb-lb1==b[i]-b1[i]) ans++;
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
