#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q;
int len[N];
string s1[N],s2[N]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],len[i]=s1[i].size(),s1[i]=" "+s1[i],s2[i]=" "+s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int siz1=t1.size(),siz2=t2.size();
		t1=" "+t1,t2=" "+t2;
		long long ans=0;
		for(int l=1;l<=siz1;l++){
			for(int r=l;r<=siz1;r++){
				for(int i=1;i<=n;i++){
					bool flag=0;
					if(len[i]!=siz1) continue;
					for(int k=l;k<=r;k++) if(s1[i][k-l+1]!=t1[k]) flag=1;
					if(!flag){
						for(int k=1;k<=len[i];k++){
							if(l<=k&&k<=r){
								if(s2[i][k]!=t2[k]){
									flag=1;break;
								}
							}
							else{
								if(s1[i][k]!=t2[k]){
									flag=1;break;
								}
							}
						}
						if(!flag) ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
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
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
