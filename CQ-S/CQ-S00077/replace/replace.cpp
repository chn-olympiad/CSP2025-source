#include<bits/stdc++.h>
#define online
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
int n,q;
string s[200005][3];
inline void solve(){
	string t[3];
	cin>>t[1]>>t[2];
	//第一步：寻找不同的“块”
	if(t[1]==t[2]){cout<<0<<endl;return;}//两个一模一样的，不可能换了就不一样了 
	bool k=1;
	int l=0,r=-1;
	for(int i=0;i<t[1].size();i++){
		if(t[1][i]!=t[2][i]){
			if(t[1][i-1]==t[2][i-1]){
				if(k==0){
					cout<<0<<endl;return;
				}
				else l=i;
			}
			k=0;
		}
		if(i>0&&t[1][i]==t[2][i]&&t[1][i-1]!=t[2][i-1]){
			r=i-1;
		}
	}
	if(r==-1)r=t[1].size()-1;
	//第二步：找有多少个“匹配 ”的 
	string t1="";
	ll ans=0;
	for(int i=l;i<=r;i++)t1.push_back(t[1][i]);
	for(int i=1;i<=n;i++){//每一个“需匹配块” 
		if(s[i][1].size()>=t1.size()){//必须要大，才行 
			//匹配
			int hd=0;
			int wic=s[i][1].find(t1,hd);//好像是N的时间复杂度？希望不是N^2;祝我RP++;搜集了那么多的RP干什么去了？ 
		//	cout<<s[i][1]<<' '<<wic<<endl;
			while(0<=wic&&wic<=t[1].size()){//匹配上了 
			//	cout<<"l="<<l-wic<<' '<<s[i][1].size()-wic+l<<' '<<t[1].size()<<endl;
					if(l-wic<0||s[i][1].size()-wic+l>t[1].size()){
						goto here;
					}
					for(int k=0,j=l-wic;k<t1.size();k++,j++){//再挨个匹配 
				//		cout<<t[2][j]<<' '<<s[i][2][k]<<endl;
						if(t[1][j]!=s[i][1][k]||t[2][j]!=s[i][2][k])goto here;//失配，跳出 
					}
				ans++;break;//可以，答案加上 
				here:;
				hd=wic+t1.size();
				wic=s[i][1].find(t1,hd);//仿佛find只要找到了一个就跳出（那么不会影响我下一次匹配的时间） 
			}
	//		cout<<"ans="<<ans<<endl;
		}
	}
	cout<<ans<<endl;
}

int main(){
#ifdef online
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
#endif
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)solve();
	
	return 0;
}
//需要kmp，但是忘记板子了
//自己发明一个 
//真的需要kmp吗？用了更好，但是我不想用（不会用）
//那就自己用不用kmp的吧！
//但还是需要匹配啊
//可以的 
/*

*/
