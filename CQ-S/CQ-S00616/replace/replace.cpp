#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<string> a,b;
bool check(string x1,string y1,string x2,string y2,int i,int l){
	for(int j=0;j<l;j++){
		if((x1[j]!=y1[i+j])||(x2[j]!=y2[i+j])) return false;
	}
	return true;
}
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		a.push_back(x);
		b.push_back(y);
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int ans=0,l2=x.length();
		for(int i=0;i<a.size();i++){
			string t1=a[i],t2=b[i];
			int l1=t1.length();
			if(l1>l2) continue;
			for(int j=0;j+l1<=l2;j++){
				if(check(t1,x,t2,y,j,l1)==true){
//				cout<<j<<" "<<l1<<" "<<l2<<" "<<x<<","<<t1<<"\n";
					string tt=x;
					for(int k=0;k<l1;k++){
						tt[j+k]=t2[k];
					}
//					cout<<">"<<tt<<"\n";
					if(tt==y){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
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
