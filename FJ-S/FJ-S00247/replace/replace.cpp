#include<bits/stdc++.h>
using namespace std;
int n,m;
int P=233;
struct sbb {
	int qu[27];
	vector<long long>pd;
	int gs;
} sb[6000005];
char s[6000005],S[6000005];
int cut;
int qz[5000005];
void tj() {
	int l=strlen(s);
	int nwz=0;
	for(int i=0; i<l; i++) {
		int z=s[i]-'a'+1;
		if(sb[nwz].qu[z]==0)sb[nwz].qu[z]=++cut;
		nwz=sb[nwz].qu[z];
	}
	long long ha=0;
	for(int i=0; i<l; i++) {
		ha=ha*P+S[i]-'a'+1;
	}
	sb[nwz].pd.push_back(ha);
	sb[nwz].gs++;
//	cout<<cut<<'\n';
	return ;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>s>>S;
		tj();
	}
	for(int i=1; i<=m; i++) {
		cin>>s>>S;
		int l=strlen(s);
		if(l!=strlen(S)) {
			cout<<0<<'\n';
			continue;
		}
		int gs=0;
		for(int j=0; j<l; j++) {
			if(s[j]==S[j])qz[j]=qz[j-1];
			else qz[j]=qz[j-1]+1;
		}
		for(int j=0; j<l; j++) {
			int nwz=0;
			long long nha=0;
			int J=j;
			while(sb[nwz].qu[s[J]-'a'+1]!=0&&J<l) {
				nwz=sb[nwz].qu[s[J]-'a'+1];
				nha=nha*P+S[J]-'a'+1;
				if(sb[nwz].gs!=0&&qz[J]-qz[j-1]==qz[l-1]) {
					for(auto mha:sb[nwz].pd){
						if(mha==nha)gs++;
					}
//					if(sb[nwz].pd!=0&&sb[nwz].pd==nha)gs++;
				}
//				cout<<j<<" "<<J<<" "<<gs<<'\n';
				J++;
			}
		}
		cout<<gs<<'\n';
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
*/
