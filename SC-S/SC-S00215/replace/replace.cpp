#include<bits/stdc++.h>
using namespace std;
vector<int> pre1[200005],pre2[200005];
string a[200005],b[200005],s[200005],ss[200005];
int bwz[200005][5];
int n,q,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	bool flag=true;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		int bsl=0;
		pre1[i].push_back(0);
		if(a[i][0]=='b') bsl++;
		if(a[i][0]!='a'&&a[i][0]!='b') flag=false;
		for(int j=1;j<a[i].size();j++){
			if(a[i][j]=='b') bsl++;
			if(a[i][j]!='a'&&a[i][j]!='b') flag=false;
			int xb=pre1[i][j-1];
			while(xb!=0&&a[i][j]!=a[i][xb]){
				xb=pre1[i][xb-1];
			}
			if(a[i][j]==a[i][xb]) pre1[i].push_back(xb+1);
			else pre1[i].push_back(0);
		}
		if(bsl!=1) flag=false;
		bsl=0;
		pre2[i].push_back(0);
		if(b[i][0]=='b') bsl++;
		if(b[i][0]!='a'&&b[i][0]!='b') flag=false;
		for(int j=1;j<b[i].size();j++){
			if(b[i][j]=='b') bsl++;
			if(b[i][j]!='a'&&b[i][j]!='b')flag=false;
			int xb=pre2[i][j-1];
			while(xb!=0&&b[i][j]!=b[i][xb]){
				xb=pre2[i][xb-1];
			}
			if(b[i][j]==b[i][xb]) pre2[i].push_back(xb+1);
			else pre2[i].push_back(0);
		}
		if(bsl!=1)flag=false;
	} 
	for(int i=1;i<=q;i++){
		cin>>s[i]>>ss[i];
		int bsl=0;
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]=='b') bsl++;
			if(s[i][j]!='a'&&s[i][j]!='b') flag=false;
		}
		if(bsl!=1) flag=false;
		bsl=0;
		for(int j=0;j<ss[i].size();j++){
			if(ss[i][j]=='b') bsl++;
			if(ss[i][j]!='a'&&ss[i][j]!='b') flag=false;
		}
		if(bsl!=1) flag=false;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i].size();j++){
				if(a[i][j]=='b') bwz[i][1]=j;
			}
			for(int j=0;j<b[i].size();j++){
				if(b[i][j]=='b') bwz[i][2]=j;
			}
		}
		for(int i=1;i<=q;i++){
			for(int j=0;j<s[i].size();j++){
				if(s[i][j]=='b') bwz[i][3]=j;
			}
			for(int j=0;j<ss[i].size();j++){
				if(ss[i][j]=='b') bwz[i][4]=j;
			}
		}
		for(int j=1;j<=q;j++){
			if(s[j].size()!=ss[j].size()){
				cout<<0<<'\n';
				continue;
			}
			for(int i=1;i<=n;i++){
				if(bwz[j][3]>=bwz[i][1]&&bwz[j][4]>=bwz[i][2]&&s[j].size()-bwz[j][3]>=a[i].size()-bwz[i][1]&&ss[j].size()-bwz[j][4]>=b[i].size()-bwz[i][1]&&bwz[i][1]-bwz[i][2]+bwz[j][4]==bwz[j][3]){
					ans++;
				}
			}
			cout<<ans<<endl;
			ans=0;
		}
	}
	else{
		for(int i=1;i<=q;i++){
			if(s[i].size()!=ss[i].size()){
				cout<<0<<endl;
				continue;
			}
			int be=s[i].size();
			int en=0;
			for(int j=0;j<s[i].size();j++){
				if(s[i][j]!=ss[i][j]){
					be=min(be,j);
					en=max(en,j);
				}
			}
	//		cout<<be<<' '<<en<<endl;
			for(int j=1;j<=n;j++){
				if(a[j].size()>s[i].size()) continue;
				if(s[i].size()==1){
					if(s[i]==a[j]&&ss[i]==b[j]){
						ans++;
					}
					continue;
				}
				int xb1=0,xb2=0;
				for(int k=0;k<s[i].size();k++){
					while(xb1!=0&&s[i][k]!=a[j][xb1]){
						xb1=pre1[j][xb1-1];
					}
					while(xb2!=0&&ss[i][k]!=b[j][xb2]){
						xb2=pre2[j][xb2-1];
					}
					if(xb1==a[j].size()-1&&xb2==b[j].size()-1){
						if(be>=k-xb1&&en<=k) ans++;
	//					cout<<j<<' '<<k<<endl;
					}
					if(a[j].size()>1&&xb1==a[j].size()-1){
						xb1=pre1[j][xb1-1];
					}
					if(b[j].size()>1&&xb2==b[j].size()-1){
						xb2=pre2[j][xb2-1];
					}
					if(a[j][xb1]==s[i][k]) xb1++;
					if(a[j][xb2]==s[i][k]) xb2++;
				}
			}
			cout<<ans<<endl;
			ans=0;
		}
	}
	return 0;
} 