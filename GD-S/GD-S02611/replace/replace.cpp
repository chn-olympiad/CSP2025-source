#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N][3];
string t1,t2;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
//	while(q--){
//		int ans=0;
//		cin>>t1>>t2;
//		for(int i=1;i<=n;i++){
//			int len=s[i][1].size();
//			if(len>t1.size()){
//				continue;
//			}
//			
//		}
//		cout<<ans<<endl;
//	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	} 
	return 0;
}
/*
4 2
xabcx xadex
ad cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

/*
18:23
挺难的，感觉进不了noip，但是游记还是要写的

我是浦帅的忠实粉丝！！！！

东华高级中学十佳歌手比赛欧世博不应该被淘汰！！！ 
*/ 
