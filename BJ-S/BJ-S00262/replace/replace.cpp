#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,P=29,M=5e6+10;
int n,q;
int len[N];
unsigned long long pre[M][5],hsh[N][5],A[M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s1=" "+s1;
		s2=" "+s2;
		for(int j=1;j<s1.size();j++){
			hsh[i][1]=hsh[i][1]*P+(s1[j]-'a');
		}
		for(int j=1;j<s2.size();j++){
			hsh[i][2]=hsh[i][2]*P+(s2[j]-'a');
		}
		//cout<<hsh[i][1]<<" "<<hsh[i][2]<<"\n";
		len[i]=s1.size()-1;
	}

	A[0]=1;
	for(int i=1;i<=5000001;i++){
		A[i]=A[i-1]*P;
	}

	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;

		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}

		t1=" "+t1;
		t2=" "+t2;
		for(int i=1;i<t1.size();i++){
			pre[i][1]=pre[i-1][1]*P+t1[i]-'a';
		}
		for(int i=1;i<t2.size();i++){
			pre[i][2]=pre[i-1][2]*P+t2[i]-'a';
		}
		
		for(int i=1;i<=n;i++){
			for(int j=len[i];j<t1.size();j++){
				unsigned long long x=pre[j][1]-pre[j-len[i]][1]*A[len[i]];
				unsigned long long y=pre[j][2]-pre[j-len[i]][2]*A[len[i]];
				unsigned long long xx=pre[t1.size()-1][1]-pre[j][1]*A[t1.size()-1-j];
				unsigned long long yy=pre[t2.size()-1][2]-pre[j][2]*A[t2.size()-1-j];
				unsigned long long xxx=pre[j-len[i]][1];
				unsigned long long yyy=pre[j-len[i]][2];
				if(x==hsh[i][1] && y==hsh[i][2] && xx==yy && xxx==yyy){
					ans++;
					//cout<<i<<" "<<j<<": "<<x<<" "<<y<<" "<<i<<" "<<ans<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
