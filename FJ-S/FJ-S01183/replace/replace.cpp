#include<bits/stdc++.h>
using namespace std;
string s1[300000],s2[300000];
void read(string &s){
	char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while(c<='z'&&c>='a')s+=c,c=getchar();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		read(s1[i]);
		read(s2[i]);
	}
	for(int i=1;i<=m;i++){
		string a,b;
		read(a);
		read(b);
		int as=a.size(),bs=b.size();
		if(as!=bs){
			cout<<"0\n";
			continue;
		}
		int l,r,ans=0;
		for(int j=0;j<as;j++){
			if(a[j]!=b[j]){
				l=j;
				break;   
			}
		}
		for(int j=as-1;j>=0;j--){
			if(a[j]!=b[j]){
				r=j;
				break;   
			}
		}
		for(int i=1;i<=n;i++){
			int ss1=s1[i].size();
			if(ss1>=r-l+1&&ss1<=as){
				int w=max(0,r-ss1+1);
				int aa=a.find(s1[i],w);
				while(aa<=l&&aa>=0){
					if(b.substr(aa,ss1)==s2[i]){
						ans++;
					} 
					w=aa+1;
					aa=a.find(s1[i],w);
				}
			}
		}
		cout<<ans<<'\n';
	}
}
