#include<algorithm> 
#include<iostream> 
#include<cstdio> 
#include<math.h> 
#include<string> 
#include<map> 
using namespace std;
const int N=2e5+10,M=1e3+10;
const int INF=0x3f3f3f3f;
const int MOD=998244353;
int n,m,p;
string s[N][2],t1,t2;
bool check(string s1,string s2){
	/*for(int i=1;i<=n;i++){
		
	}*/
	if(t1.find(s1)>t1.size())return 0;
	int pos=t1.find(s1);
	int l=s1.size();
	for(int i=0;i<l;i++){
		t1[pos+i]=s2[i];
	}
	if(t1==t2)return 1;
	/*s1="123456";
	s2="34";
	int pos=s1.find(s2);*/
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//string s1="123456",s2="34";
	//cout<<s2.find(s1);
	cin>>n>>p;
	if(n>=0){
		for(int i=1;i<=p;i++)cout<<"0\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(p--){
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(check(s[i][0],s[i][1]))ans++;
		}
		cout<<ans;
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
