#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,q,ans;
string sa,sb;
struct node{
	string s1;
	string s2;
}a[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){	
		cin>>sa>>sb;
		ans=0;
		string ssa=sa,ssb=sb;		
		for(int i=1;i<=n;i++){
			bool flag=true;
			int k=0;
			for(int j=0;j<sa.size();j++){
				if(sa[j]==a[i].s1[k]){
					sa[j]=a[i].s2[k];
					k++;
					j++;
					while(sa[j]==a[i].s1[k]){
						sa[j]=a[i].s2[k];
						k++;
						j++;
					}if(k==a[i].s1.size()) break;
				}
			}for(int j=0;j<sa.size();j++){
				if(sa[j]!=sb[j]) flag=false;
			}if(flag) ans++;
			sa=ssa;
		}cout<<ans<<endl;
	}
	
	return 0;
}
