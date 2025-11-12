#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+7;
int N,Q;
struct SP{string s1,s2;}s[maxn];
bool cmp(SP A,SP B){return A.s1.size()<B.s1.size();}
string t1,t2;
int wp;
vector<int>nxt[maxn];
char t[5000006];
inline int calc(int inxs){
	
	//cout<<"rec "<<t1<<' '<<inxs<<endl;
	int len=t1.size();
	int len2=s[inxs].s1.size();	
	for(int i=1;i<=len;i++)t[i]=t1[i-1];
	int j=0;
	for(int i=1;i<=min(len,wp+len2+1);i++){
		while(j&&s[inxs].s1[j]!=t[i])j=nxt[inxs][j];
		if(s[inxs].s1[j]==t[i])++j;
		if(j==len2){
//			puts("CCF");
			if(i<wp+1)continue;
			for(int pos=i-s[inxs].s1.size()+1,pos2=0;pos<=i;pos++,pos2++)
				t[pos]=s[inxs].s2[pos2];
			
			//for(int i=1;i<=len;i++)cout<<t[i]<<' ';cout<<endl;
			
			for(int i=1;i<=len;i++){
				if(t[i]!=t2[i-1])return 0;
			}
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout);
	scanf("%d %d",&N,&Q);
	for(int i=1;i<=N;i++)cin>>s[i].s1>>s[i].s2;
	sort(s+1,s+N+1,cmp);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=s[i].s1.size()+2;j++)nxt[i].push_back(0);
		nxt[i][0]=nxt[i][1]=0;
		for(int j=2;j<=s[i].s1.size();j++){
			int k=nxt[i][j-1];
			while(k&&s[i].s1[k]!=s[i].s1[j-1])k=nxt[i][k];
			if(s[i].s1[k]==s[i].s1[j-1])k++;
			nxt[i][j]=k;
		}
//		cout<<"i: "<<i<<endl;
//		for(int j=1;j<=s[i].s1.size();j++)cout<<nxt[i][j]<<' ';cout<<endl;
//		cout<<s[i].s1<<endl;
	}
	while(Q--){
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){wp=i;break;}
		}
		int ans=0;
		for(int i=1;i<=N;i++){
			if(s[i].s1.size()>t1.size())break;
			ans+=calc(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
永远猜不到的结论，写不完的数据结构。
啊啊，这道题一定一定是根号分治吧。
我看出来了？在离考试结束一个半小时前。
但我没能有勇气去写它。 

如果以后我真的写出来了，我大概会很伤心，很伤心吧。

啊啊，文化课连年级前50都进不了，何谈复建呢。 
*/
