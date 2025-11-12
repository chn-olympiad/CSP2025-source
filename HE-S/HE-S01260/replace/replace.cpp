#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
template<typename T>void read(T&x){
	int f=1;x=0;char c;
	do{c=getchar();if(c=='-')f=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));x=x*f;
}
int n,q,u,ans;
string s1,s2;
struct node{
	string x,y;
}a[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);read(q);
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	while(q--){
	ans=0;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			int k=s1.find(a[i].x);
//			cout<<k<<'\n';
			if(k!=-1){
				string o=s1.substr(0,k);
				string p=s1.substr(k+a[i].x.size(),s1.size()-k-a[i].x.size());
//				cout<<o<<'\n';
				if(o+a[i].y+p==s2)ans++;
//				cout<<o<<'\n';
//				if(o==a[i].y)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3 4
a b
b c
c d 
aa bb
aa b
a c
b a
*/

