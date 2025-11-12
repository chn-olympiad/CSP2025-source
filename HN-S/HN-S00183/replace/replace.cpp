#include<bits/stdc++.h>
using namespace std;
string a[100010],b[100010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int N,Q;
	cin>>N>>Q;
	for(int i=1;i<=N;i++){
		cin>>a[i]>>b[i];
	}
	while(Q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0;
		}
		string d1,d2;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				d1+=t1[i];
				d2+=t2[i];
			}
		}
		int ans=0;
		if(N<=100 && Q<=100){
			for(int i=1;i<=N;i++){
				int c=0;
				for(int j=0;j<a[i].size();j++){
					if(a[i][j]==d1[c] && b[i][j]==d2[c]){
						c++;
						if(c==d1.size()){
							ans++;
							//cout<<i<<endl;
							c=0;
							break;
						}
					}else if(a[i][j]!=b[i][j]){
						break;
					}
				
				}
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
/*
  n_____n
 / o   o \ 
 \+  u  +/ 
 / v   v \
样例在这里~
 希望看到这里的各位 RP++ QwQ
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
*/

