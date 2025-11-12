#include<bits/stdc++.h>
using namespace std;
//注意返回值 Ren5Jie4Di4Ling5%
const int N=2e5+5,L=5e6+5;
map<pair<string,string>,int> mp;
int now=0;
int cnt[N];
//trie
int rt[N][2];//root
int son[L][30];
vector<int> endd[L];
int cc=0;
void build(string s,int r,int num){
	for(char c:s){
		if(!son[r][c-'a'+1]){
			son[r][c-'a'+1]=++cc;
		}
		r=son[r][c-'a'+1];
	}
	son[r][0]++;//end
	endd[r].emplace_back(num);
}
//trie end
bool vis[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
//	system("FC REPLACE1.ANS REPLACE1.OUT");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		if(s1==s2){
			i--;n--;
			continue;
		}
		int l,r;
		for(int _=0;_<s1.length();_++){
			if(s1[_]!=s2[_]){
				l=_+1;
				break;//我忘写这个调5min 
			}
		}
		for(int _=s1.length()-1;_>=0;_--){
			if(s1[_]!=s2[_]){
				r=_+1;
				break;
			}
		}
		string sa=s1.substr(l-1,r-l+1);
		string sb=s2.substr(l-1,r-l+1);
		int x=mp[{sa,sb}];//num
		if(!x){
			cnt[++now]=1;
			mp[{sa,sb}]=now;
			x=now;
			rt[x][0]=++cc;
			rt[x][1]=++cc;
		}else{
			cnt[x]++;
		}
		//trie
		//left
		string s=s1.substr(0,l-1);reverse(s.begin(),s.end());
		build(s,rt[x][0],i);
		//right
		s=s1.substr(r,s1.length()-r);
		build(s,rt[x][1],i);
		//if(sa=="baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")cout<<l<<" "<<r<<" "<<s1.length()<<"  "<<s1.length()-r<<endl; 
	}
	int debug=0;
	while(q--){debug++;
		string t1,t2;cin>>t1>>t2;
		//if(debug==13){cout<<t1<<" "<<t2<<endl;
		if(t1.length()!=t2.length()){
			cout<<"0\n";
			continue;
		} 
		int l,r;
		for(int _=0;_<t1.length();_++){
			if(t1[_]!=t2[_]){
				l=_+1;
				break;
			}
		}
		for(int _=t1.length()-1;_>=0;_--){
			if(t1[_]!=t2[_]){
				r=_+1;
				break;
			}
		}
		string ta=t1.substr(l-1,r-l+1);
		string tb=t2.substr(l-1,r-l+1);
		int x=mp[{ta,tb}];//num
		if(!x){//no sol
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<N;i++)vis[i]=0;
		//trie
		//left
		string t=t1.substr(0,l-1);reverse(t.begin(),t.end());
		int rr=rt[x][0];
		for(char c:t){
			if(son[rr][0]){
				for(int xx:endd[rr])vis[xx]=1;
			}
			if(!son[rr][c-'a'+1]){
				break;
			}
			rr=son[rr][c-'a'+1];
		}
		if(son[rr][0]){
			for(int xx:endd[rr])vis[xx]=1;
		}
		//right
		t=t1.substr(r,t1.length()-r);
		rr=rt[x][1];
		int ans=0;
		bool ff=0;
		for(char c:t){
			if(son[rr][0]){
				for(int xx:endd[rr])ans+=vis[xx];
			}
			if(!son[rr][c-'a'+1]){
				ff=1;
				break;
			}
			rr=son[rr][c-'a'+1];
		}
		if(!ff && son[rr][0]){
			for(int xx:endd[rr])ans+=vis[xx];
		}
		//if(ta=="baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")cout<<l<<" "<<r<<" "<<t1.length()<<"  "<<t1.length()-r<<endl; 
		cout<<ans<<"\n";
		//}
	}
	return 0;
}
/*
16:59
抛开字符串相等的情况。 
发现每个两个替换可以搞出“本质”的替换。 
可以用 STL 把这个本质搞出来。
t的时候，先看本质是否存在。
然后，如果能配上，t1 t2 前面，后面的部分是一样的，就拿来匹配。
s输入的时候搞出本质，剩下的也一样。前面的，后面的就能搞trie了。
然后匹配。复杂度应该线性吧。 
17:24
我的鼠标开始莫名其妙会往下移。 
17:33
我电脑差点卡死；； 
17:37
监考员让我克服一下。
17:45
考虑字符串相等的情况，s1=s2。
如果要有解那么得 t1=t2，但是题目规定不存在这种情况。
那就把这个抛弃即可。qwq 
为什么样例3有些答案比输出小一半？？ 
4也是 
18:09 调出来了。是前面那个 ff 变量处的问题…… 
*/
