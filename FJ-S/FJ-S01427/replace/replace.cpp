#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
string t1,t2;
map<string,string> ma;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		 ma[s1]=s2;
		 
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t1>>t2;
		int len=t1.size(); 
		for(int i=0;i<len;i++){
			for(int j=len-1;j>i;j--){
				string x,y,z,t2f;
				for(int k=1;k<i;i++){
					x[k]=t1[k];
				}
				for(int k=i;k<=j;k++){
					y[k-i]=t1[k];
				}
				for(int k=j+1;k<len;k++){
					z[k-j-1]=t1[k];
				}
				t2f=x+ma[y]+z;
				if(t2f==t2) ans++;
				
			}
		}
		cout<<ans;
	}
	return 0;
} 
