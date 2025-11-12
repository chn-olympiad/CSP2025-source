#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int q;
struct Node{
	string a,b;
}x[N];
bool cmp(Node p,Node q){
	return p.a<q.a;
}
int search1(int L,int R,string s){
	while(L<R){
		int Mid=(L+R)/2;
		if(s>x[Mid].a) L=Mid+1;
		else R=Mid;
	}
	if(x[L].a!=s) return -1;
	else return L;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b;	
	}
	sort(x+1,x+1+n,cmp);
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		int len=a.size();
		int L=-1,R=len;
		while(L<R&&a[L+1]==b[L+1]) L++;
		while(L<R&&a[R-1]==b[R-1]) R--;
		for(int i=0;i<=L+1;i++){
			for(int j=R-1;j<len;j++){
				if(i>j) continue;
				int p=search1(1,n,a.substr(i,j-i+1));
				if(p==-1) continue;
				int k=p;
				string q=b.substr(i,j-i+1);
				while(k<=n&&x[k].a==x[p].a){
					if(x[k].b==q){
						ans++;
					}
					k++;
				}
				k=p-1;
				while(k>=0&&x[k].a==x[p].a){
					if(x[k].b==q){
						ans++;
					}
					k--;
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
