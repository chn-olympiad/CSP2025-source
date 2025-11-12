/*#include<bits/stdc++.h>
using namespace std;
const int P=131;
int n,m,ans;
unsigned long long hsh1[200005],hsh2[200005];
string t1,t2,s1,s2;
map<unsigned long long,unsigned long long>mp;
set<unsigned long long>st;
void slove(){
	ans=0;
	cin>>t1>>t2;
	hsh1[0]=t1[0]-'a';
	hsh2[0]=t2[0]-'a';
	for(int i=1;i<t1.size();i++){hsh1[i]=hsh1[i-1]*P+(t1[i]-'a');}
	for(int i=1;i<t2.size();i++){hsh2[i]=hsh2[i-1]*P+(t2[i]-'a');}
	if(t1.size()!=t2.size()){
		cout<<"0\n";
		return;
	}
	unsigned long long q=1;
	for(int l=0;l<t1.size();l++){
		unsigned long long p=1;
		for(int r=l;r<t2.size();r++){
			unsigned long long X,Y,Z,X1,Y1,Z1;
			X=hsh1[l-1];
			X1=hsh2[l-1];
			Y=hsh1[r]-hsh1[l-1]*p;
			Y1=hsh2[r]-hsh2[l-1]*p;
			Z=hsh1[t1.size()-1]-hsh1[r]*p*q;
			Z1=hsh2[t1.size()-1]-hsh2[r]*p*q;
			if(st.count(Y)){
				if(X==X1&&mp[Y]==Y1&&Z==Z1){ans++;}
			}
			p*=P;
		}
		q*=P;
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		unsigned long long hsh1,hsh2;
		for(int i=0;i<s1.size();i++){hsh1=hsh1*P+(s1[i]-'a');}
		for(int i=0;i<s2.size();i++){hsh2=hsh2*P+(s2[i]-'a');}
		mp[hsh1]=hsh2;
		st.insert(hsh1);
	}
	while(m--){slove();}
}*/
#include<bits/stdc++.h>
using namespace std;
const int P=131;
int n,m,ans;
unsigned long long hsh1[200005],hsh2[200005];
string t1,t2,s1,s2;
map<string,string>mp;
set<string>st;
void slove(){
	ans=0;
	cin>>t1>>t2;
	for(int len=1;len<=t1.size();len++){
		for(int l=0;l+len<=t1.size();l++){
			string x=t1.substr(0,l),y=t1.substr(l,len),z=t1.substr(l+len,t1.size()-l-len+1);
			string x1=t2.substr(0,l),y1=t2.substr(l,len),z1=t2.substr(l+len,t1.size()-l-len+1);
			if(x==x1&&mp[y]==y1&&z==z1){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
		st.insert(s1);
	}
	while(m--){slove();}
}
