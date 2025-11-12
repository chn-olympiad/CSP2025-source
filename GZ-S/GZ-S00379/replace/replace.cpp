//GZ-S00379 贵阳市南明区华麟学校 胡屹轩 
#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1[50000+50],s2[50000+50];
int ans;
int H(string q,string s1[],string s2[],int n,string a,string b,int l1,int r1){
	for(int i=0;i<n;i++){
		if(q.size()==s1[i].size()){
			for(int j=0;j<q.size();j++){
				if(q[j]!=s1[i][j])return 0;
			}
			for(int j=0;j<b.size();j++){
				if(s2[i][j]!=b[j])return 0;
			}
		}
		else return 0;
	}
	for(int i=0;i<l1;i++)
		if(b[i]!=a[i])return 0;
	for(int i=r1;i<n;i++)
		if(b[i]!=a[i])return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<m;i++){
		string a,b;
		cin>>a>>b;
		for(int j=0;j<n;j++){
			for(int k=1;k<n-j;k++){
				string q=a.substr(j,k);
				if(H(q,s1,s2,n,a,b,j,j+k-1)==1)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb*/
