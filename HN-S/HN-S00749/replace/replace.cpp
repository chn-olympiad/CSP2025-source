#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long LL;
int n,q;
string s1[N],s2[N];
string t1[N],t2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t1[i]>>t2[i];
		int a[N],aa=0,bb=0;
		int m=t1[i].size(),mm=t1[i].size();
		if(m!=mm){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<m;j++){
			if(t1[i][j]!=t2[i][j]){
				a[j]=1;
				aa+=1;
			}
		}
		for(int j=1;j<m;j++){
			if(a[j]==a[j-1]&&a[j]==1){
				bb+=1;
			}
		}
		if(aa!=bb+1){
			cout<<0<<endl;
			continue;
		}
		for(int k=1;k<=n;k++){
			if(s1[k]==t1[i]&&s2[k]==t2[i]){
				ans++;
			}
		}	
		for(int j=0;j<m;j++){
			for(int k=1;k<=n;k++){
//				cout<<s1[k][0]<<' '<<t1[i][j]<<'*'<<endl;
				if(s1[k][0]==t1[i][j]){					
//					cout<<s1[k]<<' '<<t1[i]<<'*'<<endl;
					int s=s1[k].size();
					if(s+j>=m){
						continue;
					}
					int b=1;
					for(int h=0;h<s;h++){
						if(s1[k][h]!=t1[i][j+h]){
							b=0;
						}
					}
					if(b){
						for(int h=0;h<s;h++){
							if(s2[k][h]!=t2[i][j+h]){
								b=0;
							}
						}
					}
					if(b){
						if(s==aa){
							ans++;
//							cout<<s1[k]<<'*'<<endl;	
						}											
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
