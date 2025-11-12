#include<bits/stdc++.h>
using namespace std;

int n,q,ans;
const int N=2e5+5;
struct node{
	string s,t;
}a[N];

void solve(string s,string t,string st,string sc){
	int pos=s.find(st,0),poss=t.find(st,0);
//	cout<<s<<" "<<st<<endl;
//	while(pos==poss&&pos!=-1){
//		s[pos]='A';
//		pos=s.find(st,0);
//	}
	if(pos==-1) return;
	int len=st.size();
	for(int i=pos;i<pos+len;i++){
		s[i]=sc[i-pos];
//		cout<<s[i]<<" "<<sc[i-pos]<<endl;
	}
//	cout<<"*** "<<s<<endl;
	if(s==t) ans++;
	return;
}

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].t;
	while(q--){
		string s,t;
		cin>>s>>t;
		ans=0;
		for(int i=1;i<=n;i++){
			solve(s,t,a[i].s,a[i].t);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
