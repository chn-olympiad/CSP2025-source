#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=200050,L=2500060;
int n,q,t[L][27],tot,ans;
int getnum(char x){
	return x-'a';
}
string s1,s2;
unordered_map<string,int> kk;
void add(string ss){
	int p=0,len=ss.size();
	for(int i=0;i<len;i++){
		int x=getnum(ss[i]);
		if(!t[p][x]) t[p][x]=++tot;
		p=t[p][x];
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	qwq;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		kk[s1+s2]++;
		add(s1);
	}
	for(int i=1;i<=q;i++){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int len=t1.size();
		t1=' '+t1;t2=' '+t2;
		int pos1=0,pos2=len+1;
		for(int j=1;j<=len;j++){
			if(t1[j]!=t2[j]){
				pos1=j;
				break;
			}
		}
		for(int j=len;j>=1;j--){
			if(t1[j]!=t2[j]){
				pos2=j;
				break;
			}
		}
//		cout<<"pos1="<<pos1<<" pos2="<<pos2<<"\n";
		for(int j=1;j<=pos1;j++){
			string h1="",h2="";
			int k=j,p=0,len2=0;
			while(t[p][t1[k]-'a']&&k<=len){
				len2++;
				h1+=t1[k];h2+=t2[k];
//				cout<<"j="<<j<<" h1="<<h1<<" h2="<<h2<<"\n";
				p=t[p][t1[k]-'a'];
				if(j+len2-1>=pos2){
					ans+=kk[h1+h2];
				}
				k++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
