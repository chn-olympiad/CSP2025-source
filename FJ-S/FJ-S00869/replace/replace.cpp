#include<bits/stdc++.h>
using namespace std;
int n,q;
string y[200005],y2[200005];
int l[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>y[i]>>y2[i];
		l[i]=y[i].length();	
	}
	for(int i=1;i<=q;i++){
		int cnt=0;
		string a,b;
		cin>>a>>b;
		int l2=a.length();
		for(int j=1;j<=n;j++){
			for(int k=0;k+l[j]<=l2;k++){
				if(a.substr(k,l[j])!=y[j]){
					continue;
				} 
				//cout<<a.substr(0,k)+y2[j]+a.substr(k+l[j],l2-k-l[j])<<'\n';
				if(a.substr(0,k)+y2[j]+a.substr(k+l[j],l2-k-l[j])==b){
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
