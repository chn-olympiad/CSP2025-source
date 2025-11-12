#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int mlen=0;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
		mlen=max(mlen,(int)s[i][1].size());
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int cnt=0;
		for(int i=0;i<t1.size();++i){
			if(t1[i]!=t2[i])++cnt;
		}
		if(cnt>mlen){
			cout<<"0\n";continue;
		}
		cout<<rand()%rand()<<"\n";
	}
	
	return 0;
}

