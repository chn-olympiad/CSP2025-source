#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
typedef long long ll;
ll q,n;
string s1[N],s2[N],x1,x2;
string tmp;
inline ll read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}


int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
//	for(int i=1;i<=q;i++){
//		cin>>x1>>x2;
//		if(s1.size()!=s2.szie()){
//			cout<<0<<'\n';
//			continue;
//		}
//		for(int j=1;j<=n;j++){
//			if(s1[j].size()>x1.size()) continue;
//			for(int f=0;f<=t1.size()-s1[j].szie();f++){
//				if(t1[f])
//			}
//		}
//	}
	return 0;
}
/*

*/
