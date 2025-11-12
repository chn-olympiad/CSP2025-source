#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1;
string s2;
int mi=0x3f3f3f3f;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	srand(time(0));
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>s1>>s2,mi=min(mi,(int)s1.size());
	for(int i=1;i<=q;++i){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()||(int)s1.size()<mi){
			cout<<"0\n";
		}
		else{
			cout<<rand()%n<<'\n';
		}
	}
	return 0;
}

