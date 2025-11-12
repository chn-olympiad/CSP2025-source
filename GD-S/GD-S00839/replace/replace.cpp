#include<bits/stdc++.h>
using namespace std;
int n,q;
string a1[200020],a2[200020];
int ans;
string t1,t2;
void solve(int f1,int f2){
	for(int i=1;i<=n;i++){
		if(a1[i].size()>t1.size())continue;
		int v1=a1[i].find('b'),v2=a2[i].find('b');
		string p1=t1.substr(f1-v1,a1[i].size());
		string p2=t2.substr(f2-v2,a2[i].size());
		if(p1==a1[i]&&p2==a2[i]){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		
		
		bool b=false;
		for(auto i:t1){
			if(i!='a'&&i!='b')b=true;
			break;
		}
		if(!b){
			for(auto i:t2){
				if(i!='a'&&i!='b')b=true;
				break;
			}
			if(!b){
				int f1=t1.find('b');
				if(t1.find('b',f1+1)==string::npos){
					int f2=t2.find('b');
					if(t2.find('b',f2+1)==string::npos){
						//cerr<<"specail!\n";
						solve(f1,f2);
						continue;
					}
				}
			}
		}
		
		
		for(int i=1;i<=n;i++){
			string p=t1.substr(0,a1[i].size()),pre="";
			if(p==a1[i]&&a2[i]+t1.substr(a1[i].size())==t2){
				ans++;
				cerr<<"start:"<<i<<" "<<a2[i]+p.substr(a1[i].size())<<'\n';
			}
			for(int j=a1[i].size();j<t1.size();j++){
				pre+=p.front();
				p=p.substr(1)+t1[j];
				if(p==a1[i]&&pre+a2[i]+t1.substr(j+1)==t2){
					ans++;
					cerr<<pre+a2[i]+t1.substr(j+1)<<'\n';
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//rp ++
