#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string s[200005],b[200005];
int t[5000005],ans=0,n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
           cin>>s[i]>>b[i];
    for(int l=1;l<=q;l++){
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++){
		    if(i==0) t[i]=0;
		    else t[i]=t[i-1];
		    if(s1[i]==s2[i]) t[i]++;
		}
		string s3=s1;
		for(int i=0;i<s1.size();i++){
			if(i!=0&&t[i-1]!=i) break;
	    	for(int j=1;j<=n;j++){
				s3=s1; int p=0;
				for(int k=i;k<s1.size()&&k<i+s[j].size();k++){
				    if(s1[k]!=s[j][k-i]) {
						 p=1; break;
					}
				    s3[k]=b[j][k-i];
				}
				if(p==0&&s3==s2) ans++;
			}
		}
		cout<<ans<<endl; ans=0;
	}
    fclose(stdin); fclose(stdout);
    return 0;
}
