#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans=0;
string s[200010][3];
string t[200010][3];
string zzt[200010],zjx[200010];
bool bh(string we,string wer){  //we «∑Ò‘⁄wer÷– 
	bool su=0;
	for(int i=0;i<wer.size();i++){
		if(we[0]==wer[i]){
//			cout<<"i="<<i<<"\n";
			for(int j=1;j<we.size();j++){
				if(we[j]!=wer[j+i]){
//					cout<<"j="<<j<<"\n";
					break;
				}
				if(j==we.size()-1) su=1;
			}
		}
	}
	return su;
}
string th(string we,string we1,string wer){
	for(int i=0;i<wer.size();i++){
		if(we[0]==wer[i]){
			for(int j=1;j<we.size();j++){
				if(we[j]!=wer[j+i]){
					break;
				}
				if(j==we.size()-1) {
					int cc=i;
					for(int o=0;o<we.size();o++){
						wer[cc]=we1[o];
						cc++;
					}
					return wer;
				}
				
			}
		}
	}
//	cout<<"we="<<we<<"\n";
//	cout<<"wer="<<wer<<" \n";
	return wer;
}
int cnm[500010],cnt1,cnt2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++) cin>>t[i][1]>>t[i][2];  
	
	bool p=0;//special B
	for(int j=0;j<t[1][1].size();j++){
		if(t[1][1][j]!='a'&&t[1][1][j]!='b'){
			p=1;
			break;
		}
	}
	if(!p){
		for(int i=1;i<=n;i++){
			for(int j=0;j<s[i][1].size();j++){
				if(s[i][1][j]=='b') cnt1=j;
				if(s[i][2][j]=='b') cnt2=j;
			}
			cnm[i]=cnt1-cnt2;
		}
		for(int i=1;i<=q;i++){
			ans=0;
			for(int j=0;j<t[i][1].size();j++){
				if(t[i][1][j]=='b'){
					swap(t[i][1][j],t[i][1][j-cnm[i]]);
//					t[i][1][j]='a';
//					int wtf=cnm[j];
//					t[i][1][j-wtf]='b';
					if(t[i][1]==t[i][2]) ans++;
					swap(t[i][1][j],t[i][1][j-cnm[i]]);
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	} 
	
	for(int i=1;i<=q;i++){
		if(t[i][1].size()!=t[i][2].size()) {
			cout<<"0\n";
			continue;
		}
		ans=0;
		int len=t[i][1].size();
//		for(int j=0;j<len;j++){
//			if(t[i][1][j]!=t[i][2][j]){
//				int cnt=0;
//				while(t[i][1][j]!=t[i][2][j]){
//					zzt[i][cnt]=t[i][1][j],zjx[i][cnt]=t[i][2][j];
//					cnt++;
//					j++;
//				}
//			}
//		}
		for(int j=1;j<=n;j++){
			if(bh(s[j][1],t[i][1])){
				string ts=t[i][1];
				ts=th(s[j][1],s[j][2],ts);
				if(ts==t[i][2]) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 



