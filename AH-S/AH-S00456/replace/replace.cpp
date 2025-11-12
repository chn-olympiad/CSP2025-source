#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	bool f=false;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int cntna1=0,cntb1=0,cntna2=0,cntb2=0;
		for(int j=0;j<(int)(s1[i].size());j++){
			if(s1[i][j]!='a'){
				cntna1++;
				if(s1[i][j]=='b') cntb1++;
			}
			if(s2[i][j]!='a'){
				cntna2++;
				if(s2[i][j]=='b') cntb2++;
			}
		}
		if(cntna1!=1||cntb1!=1||cntna2!=1||cntb2!=1) f=true; 
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int cntna1=0,cntb1=0,cntna2=0,cntb2=0;
		for(int i=0;i<(int)(t1.size());i++){
			if(t1[i]!='a'){
				cntna1++;
				if(t1[i]=='b') cntb1++;
			}
			if(t2[i]!='a'){
				cntna2++;
				if(t2[i]=='b') cntb2++;
			}
		}
		if(cntna1!=1||cntb1!=1||cntna2!=1||cntb2!=1) f=true;
		if(f==false){
			int s1b,s2b,t1b,t2b,ans=0;
			for(int i=0;i<(int)(t1.size());i++){
				if(t1[i]=='b') t1b=i;
				if(t2[i]=='b') t2b=i;
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<(int)(s1[i].size());j++){
					if(s1[i][j]=='b') s1b=j;
					if(s2[i][j]=='b') s2b=j;
				}
				if((s2b-s1b==t2b-t1b)&&(int)(t1.size())-t1b>=(int)(s1[i].size())-s1b&&(int)(s1[i].size())<=(int)(t1.size())&&s1b<=t1b) ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
