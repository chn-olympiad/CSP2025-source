#include<bits/stdc++.h>
#define MAXN 5000005
#define int long long

using namespace std;
namespace FastIO
{
	inline string _rs()
	{
		string str="";
		int ch=getchar();
		while(ch==' ' || ch=='\n' || ch=='\r') ch=getchar();
		while(ch!=' ' && ch!='\n' && ch!='\r' && ch!=EOF){
			str.push_back(ch);
			ch=getchar();
		}
		return str;
	}
	inline void _ws(string a,char b)
	{
		int len=a.size();
		for(int i=0;i<len;i++) putchar(a[i]);
		putchar(b);
		return ;
	}
	inline int _r()
	{
		int flag=1,ans=0,ch=getchar();
		while((ch<'0' || ch>'9') && ch!=EOF){
			if(ch=='-') flag=-1;
			ch=getchar();
		}
		while(ch>='0' && ch<='9'){
			ans=(ans<<1)+(ans<<3)+(ch^48);
			ch=getchar();
		}
		return flag*ans;
	}
	inline void _w(int a,char b)
	{
		if(a<0) a=-a,putchar('-');
		int sta[22],top=0;
		do{
			sta[top++]=a%10;
			a/=10;
		}while(a);
		while(top) putchar(sta[--top]+48);
		putchar(b);
		return ;
	}
}
using namespace FastIO;

int n,q,kmp[MAXN],appe[MAXN],cnt,L,R;
string s[5][MAXN],t[5];
stack<int> sta;

void KMP(int p1,int P,int p2)
{
	int len1=s[p1][P].size()-1,len2=t[p2].size()-1;
	if(len1>len2) return ;
	kmp[1]=0;
	for(int i=2;i<=len1;i++){
		kmp[i]=kmp[i-1];
		while(kmp[i] && s[p1][P][kmp[i]+1]!=s[p1][P][i]) kmp[i]=kmp[kmp[i]];
		if(s[p1][P][kmp[i]+1]==s[p1][P][i]) kmp[i]++;
	}
	
	for(int i=1,j=0;i<=len2;i++){
		while(j && s[p1][P][j+1]!=t[p2][i]) j=kmp[j];
		if(s[p1][P][j+1]==t[p2][i]) j++;
		//cout<<"\t"<<i<<" "<<j<<" "<<endl;///////////////////////////////////////////////
		if(j==len1){
			appe[i]++;
			sta.push(i);
			if(appe[i]==2 && i>=R && i-len1<L) cnt++;
		}
	}
	//cout<<endl;////////////////////////////////////
	return ;
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=_r(),q=_r();
	for(int i=1;i<=n;i++) s[1][i]=" "+_rs(),s[2][i]=" "+_rs();
	for(int i=1;i<=q;i++){
		t[1]=" "+_rs(),t[2]=" "+_rs();
		int len=t[1].size()-1;
		L=R=-1;
		for(int j=1;j<=len;j++){
			if(t[1][j]!=t[2][j]){
				if(L==-1) L=j;
				R=j;
			}
		}
		
		cnt=0;
		for(int j=1;j<=n;j++){
			sta=stack<int>();
			KMP(1,j,1);
			KMP(2,j,2);
			while(!sta.empty()){
				appe[sta.top()]=0;
				sta.pop();
			}
		}
		_w(cnt,'\n');
	}
	
	return 0;
}
