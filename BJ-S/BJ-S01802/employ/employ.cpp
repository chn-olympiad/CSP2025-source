
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
using namespace std;
ll read(){
	ll k=0;bool flag=1;char c=getchar_unlocked();
	while(!isdigit(c)){if(c=='-')flag=0;c=getchar_unlocked();}
	while(isdigit(c)){k=(k<<1)+(k<<3)+(c^48);c=getchar_unlocked();}
	if(flag)return k;else return -k;
}
char readc(){
	char c=getchar_unlocked();
	while(!isgraph(c))c=getchar_unlocked();
	return c;
}
string reads(){
	string str="";char c=getchar_unlocked();
	while(!isgraph(c))c=getchar_unlocked();
	while(isgraph(c)){str+=c;c=getchar_unlocked();}
	return str;
}
const int N=510;
int n,m,c[N],a[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;++i)c[i]=read(),a[i]=i;
	int ans=0;
	do{
		int cnt=0,num=0;
		for(int i=1;i<=n;++i){
			if(cnt>=c[a[i]])++cnt;
			else{
				if(s[i]=='1')++num;
				else ++cnt;
			}
		}
		if(num>=m){
			++ans;
		}
	}
	while(next_permutation(a+1,a+1+n));
	cout<<ans;
    return 0;
}
// -std=c++14 -O2 
