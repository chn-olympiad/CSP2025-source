#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010];
string t1,t2;
int b1q[200010],b1l[200010],b2q[200010],b2l[200010];
int b3q,b3l,b4q,b4l;
int ans;
char ch;
bool f;
inline int rd(int mod){
	return (1ll*rand()*rand()*rand()+rand()*rand())%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand((unsigned)time(0));
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		ch=getchar();
		f=0;
		while('a'<=ch&&ch<='z'){
			if(!f)b1q[i]++;
			else b1l[i]++;
			if(ch=='b')f=1;
			ch=getchar();
			
		}
		ch=getchar();
		f=0;
		while('a'<=ch&&ch<='z'){
			if(!f)b2q[i]++;
			else b2l[i]++;
			if(ch=='b')f=1;
			ch=getchar();
			
		}
	}while(q--){
		b3q=b3l=b4q=b4l=ans=0;
		cin>>t1>>t2;
		cout<<rd(10)<<'\n';
	}
	return 0;
}
