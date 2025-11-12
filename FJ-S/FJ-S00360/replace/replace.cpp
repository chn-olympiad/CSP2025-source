#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s;
struct Node{
	string st,str;
}a[N];
int n,q,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;cin>>a[i].st>>a[i].str,i++);
	for(int i=1;i<=q;i++){
		string t,tr;
		cin>>t>>tr,s=t;
		if(t.size()!=tr.size()){cout<<"0\n";continue;}
		for(int j=1;j<=n;j++){
			bool pd=1,Pd=0;
			for(int k=0;k<t.size();k++){
				for(int l=0;l<=a[i].st.size();l++)
					if(t[k+l]!=a[i].st[l]){pd=0;break;}
				if(pd){
					int pd2=1;
					for(int l=0;l<a[i].st.size();l++) s[k+l]=a[i].st[l];
					Pd=1;
					for(int l=0;l<s.size();l++) if(s[l]!=tr[l]){pd2=0;break;}
					if(pd2){ans++;break;}
				}
			}
		}
		cout<<ans<<'\n';ans=0;
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
