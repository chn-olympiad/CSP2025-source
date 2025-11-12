#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,q,bl[N][3],br[N][3],ans;
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].length();j++){
			if(s1[i][j]=='b'){
				bl[i][1]=j;
				br[i][1]=s1[i].length()-j-1;
				break;
			}
		}
		for(int j=0;j<s2[i].length();j++){
			if(s2[i][j]=='b'){
				bl[i][2]=j;
				br[i][2]=s2[i].length()-j-1;
				break;
			}
		}
	}
	string t1,t2;
	int l1,r1,l2,r2;
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		ans=0;
		for(int j=0;j<t1.length();j++){
			if(t1[j]=='b'){
				l1=j;
				r1=t1.length()-j-1;
				break;
			}
		}
		for(int j=0;j<t2.length();j++){
			if(t2[j]=='b'){
				l2=j;
				r2=t2.length()-j-1;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(s1[j].length()>t1.length()||bl[j][1]>l1||br[j][1]>r1||bl[j][2]>l2||br[j][2]>r2) continue;
			else if(bl[j][1]-bl[j][2]==l1-l2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
