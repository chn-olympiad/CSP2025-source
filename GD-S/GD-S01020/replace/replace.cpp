#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string str1[n+1]={};
	string str2[n+1]={};
	string q1[q+1]={};
	string q2[q+1]={};
	for(int i=1;i<=n;i++){
		cin>>str1[i]>>str2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>q1[i]>>q2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		int len=q1[i].length();
		for(int j=1;j<=len;j++){
			for(int l=1;l<=n;l++){
				if(q1[i][j]==str1[l][1]){
					bool flag=true;
					for(int x=1;x<=str1[l].length();x++){
						if(q1[i][j+x]!=str1[l][1+x]||str1[l][1+x]!=q2[i][j+x]){
							flag=false;
						}
					}
					if(flag==true){
						ans++;
					}
				}
			} 
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
