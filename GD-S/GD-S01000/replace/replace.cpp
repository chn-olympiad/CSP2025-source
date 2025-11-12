#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=2e5+5;
int n,q;
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		int cnt=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			vector<int>v1,v2;
			size_t p=0;
			p=t1.find(s1[i]);
			while(p!=t1.npos){
				v1.push_back(p);
				p=t1.find(s1[i],p+1);
			}
			p=t2.find(s2[i]);
			while(p!=t2.npos){
				v2.push_back(p);
				p=t2.find(s2[i],p+1);
			}
			size_t p1=0,p2=0;
			while(p1<v1.size()&&p2<v2.size()){
				if(v1[p1]<v2[p2]){
					if(p1+1==v1.size())break;
					p1++;
				}else if(v1[p1]>v2[p2]){
					if(p2+1==v2.size())break;
					p2++;
				}else{
					string str=t1;
					if(str.replace(v1[p1],s1[i].size(),s2[i])==t2)cnt++;
					if(p1+1==v1.size()||p2+1==v2.size())break;
					p1++,p2++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
/*
note:
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
KMP/Tire/哈希？依然不会 
我是蒟蒻 
*/

