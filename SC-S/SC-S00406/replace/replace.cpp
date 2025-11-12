#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 200005
#define ll long long
#define mod 998244353
int n,m,q,b1,b2,ans;
string t1,t2;
struct node{
	string s1,s2;
}thj[N];
struct node2{
	int b1,b2;
}bw[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>thj[i].s1>>thj[i].s2;
		for(int i=1;i<=thj[i].s1.size();i++){
			if(thj[i].s1[i]=='b'){
				bw[i].b1=i;
				break;
			}
		}
		for(int i=1;i<=thj[i].s2.size();i++){
			if(thj[i].s2[i]=='b'){
				bw[i].b2=i;
				break;
			}
		}
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		t1=" "+t1;
		t2=" "+t2;
		for(int i=1;i<=t1.size();i++){
			if(t1[i]=='b'){
				b1=i;
				break;
			}
		}
		for(int i=1;i<=t2.size();i++){
			if(t2[i]=='b'){
				b2=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(bw[i].b1==b1 && bw[i].b2==b2){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}