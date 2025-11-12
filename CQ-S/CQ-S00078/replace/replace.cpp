#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[1010];
string s1[1010];
string t[1010];
string t1[1010];
int l[1999],r[1999];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cin>>s1[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i];
		cin>>t1[i];
		int flag=1;
		for(int j=0;j<s[i].size();j++){
			if(t[j]!=t1[j]&&flag==1){
				l[i]=j;
				flag=0;
				break;
			}
		}
		for(int j=s[i].size();j>=0;j--){
			if(t[j]!=t1[j]&&flag==0){
				r[i]=j;
				break;
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int cnt=0;
		int len=r[i]-l[i]+1;
		for(int j=1;j<=n;j++){
			if(s[j].size()==len){
				int flag=0;
				for(int k=l[i];k<=r[i];k++){
					if(t[i][k]!=s[j][k-l[i]]) {
						flag=1;
						break;
					}
				}
				if(flag==0){
					for(int k=l[i];k<=r[i];k++){
						if(t1[i][k]!=s1[j][k-l[i]]) {
							flag=-1;
							break;
						}
					}
					if(flag==-1){
						cnt++;
					}
				}
			}
		} 
		cout<<cnt<<"\n";
	}
	return 0;
} 
