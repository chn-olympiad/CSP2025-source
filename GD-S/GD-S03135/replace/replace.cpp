#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#define gc() getchar()

using std::min;
using std::max;
using std::cin;
using std::cout;
using std::sort;
using std::string;

const int N=2e5+5;

int n,q,ans;
int s1l[N],s2l[N];
string s1,s2,t1,t2;
void si(string&s){s.erase(0);for(char ch=gc();ch!='\n'&&ch!=' ';ch=gc())s+=ch;}
int main(){
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1>>s2,s1l[i]=s1.size(),s2l[i]=s2.size();
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int nt1=t1.size(),nt2=t2.size(),ans=0;
		for(int j=1;j<=n;j++) if(nt1-s1l[j]+s2l[j]==nt2) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
