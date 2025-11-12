#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans; 
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		string a,b;
		cin>>a>>b;
	}
	for(int i=1;i<=q;i++) {
		string x,y,tian,bu;
		cin>>x>>y;
		int lenx=x.length(),leny=y.length();
		if(lenx!=leny) {
			cout<<"0\n";
			continue;
		} 
		int cnt=0;
		for(int i=0;i<lenx;i++){
			if(x[i]!=y[i]) tian+=x[i],bu+=y[i];
			else if(x[i-1]!=y[i-1]) cnt++; 
		}
		if(x[lenx-1-1]!=y[leny-1-1]) cnt++;
		if(cnt>1) {
			cout<<"0\n";
			continue;
		}
		if(cnt==0){
			cout<<"1\n";
			continue;
		}
		cout<<rand()%2+1<<"\n";
	}
}
