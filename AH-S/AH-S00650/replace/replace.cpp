#include <bits/stdc++.h>
using namespace std;
int n,q,sumn,t1q,t1h,t2q,t2h;
int b1q[200005],b1h[200005],b2q[200005],b2h[200005];
string s1[200005],s2[200005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=n;++i){
		for(int j=0;j<int(s1[i].size());++j){
			if(s1[i][j]=='b'){
				b1q[i]=j;
				b1h[i]=s1[i].size()-j-1;
			}
		}
		for(int j=0;j<int(s2[i].size());++j){
			if(s2[i][j]=='b'){
				b2q[i]=j;
				b2h[i]=s2[i].size()-j-1;
			}
		}
	}
	for(int i=1;i<=q;++i){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0"<<'\n';
			continue;
		}
		sumn=0;
		for(int i=0;i<int(t1.size());++i){
			if(t1[i]=='b'){
				t1q=i;
				t1h=t1.size()-i-1;
			}
		}
		for(int i=0;i<int(t2.size());++i){
			if(t2[i]=='b'){
				t2q=i;
				t2h=t2.size()-i-1;
			}
		}
		for(int i=1;i<=n;++i)
			if(b1q[i]<=t1q&&b1h[i]<=t1h&&b2q[i]<=t2q&&b2h[i]<=t2h)
				if(b1q[i]-b2q[i]==t1q-t2q&&b1h[i]-b2h[i]==t1h-t2h)
					++sumn;
		cout<<sumn<<'\n';
	}
	return 0;
}
