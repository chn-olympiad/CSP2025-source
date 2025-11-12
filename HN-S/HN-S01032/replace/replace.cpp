#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
#define ll long long
int kmp1[MAXN][MAXN],kmp2[MAXN][MAXN];
string s1[MAXN],s2[MAXN];
string t1,t2;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]="#"+s1[i];
		s2[i]="#"+s2[i];
	}
	for(int i=1;i<=n;i++){
		int len=s1[i].size()-1;
		int pos=0;
		for(int j=2;j<=len;j++){
			while(pos&&s1[i][pos+1]!=s1[i][j])pos=kmp1[i][pos];
			if(s1[i][pos+1]==s1[i][j])pos++;
			kmp1[i][j]=pos;
			//cout<<kmp1[i][j]<<" ";
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++){
		int len=s2[i].size()-1;
		int pos=0;
		for(int j=2;j<=len;j++){
			while(pos&&s2[i][pos+1]!=s2[i][j])pos=kmp2[i][pos];
			if(s2[i][pos+1]==s2[i][j])pos++;
			kmp2[i][j]=pos;
		//	cout<<kmp2[i][j]<<" ";
		}
		//cout<<endl;
	}
	while(q--){
		cin>>t1>>t2;
		int len=t1.size();
		int lenn=t2.size();
		if(len!=lenn){
			cout<<"0"<<endl;
			continue;
		}
		int l=len+1,r=0;
		t1="#"+t1;
		t2="%"+t2;
		for(int i=1;i<=len;i++){
			if(t1[i]!=t2[i]){
				l=min(l,i);
				r=max(r,i);
			}
		}
		//cout<<l<<" "<<r<<endl;
		//cout<<len<<" ";
		int ans=0;
		for(int i=1;i<=n;i++){
			int pos1=0,pos2=0;
			//cout<<"!";
			for(int j=1;j<=len;j++){
				//cout<<j<<" ";
				while(pos1&&s1[i][pos1+1]!=t1[j])pos1=kmp1[i][pos1];
				//cout<<j<<" ";
				while(pos2&&s2[i][pos2+1]!=t2[j])pos2=kmp2[i][pos2];
				//cout<<j<<endl;
				if(s1[i][pos1+1]==t1[j])pos1++;
				if(s2[i][pos2+1]==t2[j])pos2++;
				if(pos1==pos2&&pos1==s1[i].size()-1&&j>=r&&j-pos1+1<=l)ans++;
				if(pos1==s1[i].size()-1)pos1=kmp1[i][pos1];
				if(pos2==s2[i].size()-1)pos2=kmp2[i][pos2];
				//cout<<ans<<" V";
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
