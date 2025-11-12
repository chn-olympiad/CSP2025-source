#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
struct R{
	string s,t;
}a[200010];
bool cmp(R x,R y){
	return x.s<y.s;
}
lld n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string l,r;int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].t;
		if(f!=0){
			int x=a[i].s.size();int w=0,p=0;
			for(int j=1;j<=x;i++){
				w+=a[i].s[j]-'a';
				p+=a[i].s[j]-'b';
			}
			if((w+p==x)&&(p==1))f=2;
			else f=1;
		}
	}
	if(f==2){
		
	}
	if(n<10010){
		sort(a+1,a+n+1,cmp);
		while(q--){
			cin>>l>>r;
			
		}
	}
	while(q--){
		cout<<0;
	}
	return 0;
}