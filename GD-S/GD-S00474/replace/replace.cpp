#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
string s1[N],s2[N];
string t1,t2,t3;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,q; cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2; cin>>t1>>t2;
		int m=t1.length(),ans=0;
		for(int i=1;i<=n;i++){
			int k=s1[i].length();
			for(int j=0;j<m;j++){
				bool flg=true;
				for(int l=0,r=j;l<k,r<m-l;l++,r++){
					if(t1[r]!=s1[i][l]){
						flg=false;
						break;
					}
				}
				if(flg){
					t3=t1;
					for(int l=0;l<k;l++) t3[j+l]=s2[i][l];
					if(t3==t2) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
