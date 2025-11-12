#include <bits/stdc++.h>
using namespace std;
struct T{
	string s1,s2;
}a[200010];
string t1,t2;
int n,q;
bool xt(string s1,int l,string s){
	int ll=int(s.size());
	for(int i=0;i<ll;i++){
		if(i>=int(s1.size())) return false;
		if(s1[l+i]!=s[i]) return false;
	}
	return true;
}
bool th(string s1,int l,int b){
	int ll=int(a[b].s2.size());
	for(int i=0;i<ll;i++) s1[l+i]=a[b].s2[i];
	if(xt(s1,0,t2)) return true;
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) cout<<"0\n";
		else{
			int sum=0;
			for(int i=0;i<int(t1.size());i++){
				for(int j=1;j<=n;j++){
					if(xt(t1,i,a[j].s1)){
						if(th(t1,i,j)) sum++;
					}
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
