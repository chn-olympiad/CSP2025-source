#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=1e9;
int n,q;
string s[N][3];
int lens[N],cnts[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		lens[i]=s[i][1].length();
		s[i][1]=' '+s[i][1];
		s[i][2]=' '+s[i][2];
		for(int j=1;j<=lens[i];j++)
			if(s[i][1][j]!=s[i][2][j]) cnts[i]++;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		int cntt=0,lent=t1.length();
		t1=' '+t1;
		t2=' '+t2;
		int l=inf,r=0;
		for(int j=1;j<=lent;j++)
			if(t1[j]!=t2[j]){
				cntt++;
				l=min(l,j);
				r=max(r,j);
			}
		for(int j=1;j<=n;j++){
			if(lens[j]<r-l+1 || cnts[j]!=cntt) continue;
			for(int k=max(r-lens[j]+1,1);k<=min(l,lent-lens[j]+1);k++){
				//cout<<"k="<<k<<"\n";
				string temp1=t1.substr(k,lens[j]);
				temp1=' '+temp1;
				if(temp1!=s[j][1]) continue;
				string temp2=t2.substr(k,lens[j]);
				temp2=' '+temp2;
				if(temp2==s[j][2]){
					//cout<<s[j][1]<<" "<<s[j][2]<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}