#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
struct node{
	string s1,s2;
	int l1,l2;
} w[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>w[i].s1>>w[i].s2,w[i].l1=w[i].s1.length(),w[i].l2=w[i].s2.length();
	while(q--){
		int ans=0,lx1,lx2;
		string x1,x2;
		cin>>x1>>x2;
		lx1=x1.length(),lx2=x2.length();
		if(lx1!=lx2) {
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<lx1;i++){
			for(int j=i;j<lx1;j++){
				for(int k=1;k<=n;k++){
					if(j-i+1!=w[k].l1) continue;
					int f=0;
					for(int l=i,ll=0;l<=j;l++,ll++){
						if(x1[l]!=w[k].s1[ll]){
							f=1;
							break;
						}
					}
					if(f==1) continue;
					string t;
					int cnt=0;
					for(int l=0;l<lx1;l++){
						if(l>=i&&l<=j) t[l]=w[k].s2[cnt],cnt++;
						else t[l]=x1[l];
					}
					f=0;
					for(int l=0;l<lx2;l++){
						if(t[l]!=x2[l]){
							f=1;
							break;
						}
					}
					if(f==0) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
