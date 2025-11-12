#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,q;
int l[200001] = {0},l2[200001] = {0};
string str1[200001],str2[200001],t1[200001],t2[200001];
vector<int>nxt[200001];
int L1 = 0,L2 = 0;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>str1[i]>>str2[i];
		l[i] = str1[i].length();
		L1+=2*l[i];
		str1[i]+=".";
		nxt[i].push_back(0);
		for(int j = 1;j<=l[i];j++){
			nxt[i].push_back(0);
		}
		for(int j = l[i];j>=1;j--){
			str1[i][j] = str1[i][j-1];
		}
		int dpos = 0;
		for(int j = 2;j<=l[i];j++){
			while(dpos and str1[i][dpos+1]!=str1[i][j])dpos = nxt[i][dpos];
			if(str1[i][dpos+1]==str1[i][j])dpos++;
			nxt[i][j] = dpos;
		}
//		for(int j = 1;j<=l[i];j++){
//			cout<<nxt[i][j]<<" ";
//		}
//		cout<<endl;
	}
//	for(int i = 1;i<=n;i++)cout<<l[i]<<" ";
//	cout<<endl;
//	if(L1>=1000000 and q>1000){
//		
//	}
	for(int i = 1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		if(t1[i].length()!=t2[i].length()){
			cout<<0<<endl;
			continue;
		}
		l2[i] = t1[i].length();
		t1[i]+=".";
		t2[i]+=".";
		for(int j = l2[i];j>=1;j--){
			t1[i][j] = t1[i][j-1];
		}
		for(int j = l2[i];j>=1;j--){
			t2[i][j] = t2[i][j-1];
		}
		int dl = 1,dr = l2[i];
		while(t1[i][dl]==t2[i][dl])dl++;
		dl--;
		while(t1[i][dr]==t2[i][dr])dr--;
		dr++;
//		cout<<dl<<" "<<dr<<endl;
		int ddans = 0;
		for(int j = 1;j<=n;j++){
			int dpos = 0,fl = 0;
			for(int k = 1;k<=l2[i];k++){
				while(dpos and str1[j][dpos+1]!=t1[i][k])dpos = nxt[j][dpos];
				if(str1[j][dpos+1]==t1[i][k])dpos++;
				if(dpos==l[j]){
					fl = k-l[j]+1;
					break;
				}
			}
			if(fl){
//				cout<<fl<<endl;
				bool ddfl = 1;
				for(int k = fl;k<=fl+l[j]-1;k++){
//					cout<<str2[j][k-fl]<<" "<<t2[i][k]<<endl;
					if(str2[j][k-fl]!=t2[i][k]){
						ddfl = 0;
						break;
					}
				}
				if(fl>dl+1 or fl+l[j]-1<dr-1){
					ddfl = 0;
				}
				ddans+=ddfl;
			}
		}
		cout<<ddans<<endl;
	}
	return 0;
}
/*
kancuotileaaaaaaaaaaaaaaaa
ciallo!17:02
17:28KMP over.think about comp.
50(1-6withA)shouldnotbetoohardqwq
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
5 1
abacbb abecaa
abacaa abecbb
acaad ecbbd
aba abe
eecb ccdf
abacaade abecbbde
End at 18:08.
B is also ez but idontwannatry
18:26
end!
*/
