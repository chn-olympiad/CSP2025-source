#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		int x=0;
		while(t1[x]==t2[x]){
			x++;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int y=0;
			bool flag=1;
			while(s1[i][y]==s2[i][y]){
				y++;
			}
			for(int j=x-y;j<x;j++){
				if(s1[i][j-x+y]!=t1[j]){
					flag=0;
					break;
				}
			}
			//cout<<x-y<<" "<<x-1<<"\n";
			if(!flag)continue;
			for(int j=x;j-x+y<(int)s1[i].size();j++){
				if(s1[i][j+y-x]!=t1[j]||s2[i][j+y-x]!=t2[j]){
					flag=0;
					break;
				}
			}
			//cout<<x<<" "<<s1[i].size()+x-y-1<<"\n";
			if(!flag)continue;
			for(int j=(int)s1[i].size()+x-y;j<(int)t1.size();j++){
				if(t1[j]!=t2[j]){
					flag=0;
					break;
				}
			}
			//cout<<s1[i].size()+x-y<<" "<<t1.size()-1<<"\n";
			if(!flag)continue;
			ans++;
			//cout<<i;
		}
		cout<<ans<<"\n";
	}
	return 0; 
}
/*
1 2 3 4 4 4 5 6 7 x=4
1 2 3 9 9 9 5 6 7

3 4 4 4 y=2
3 9 9 9

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

1 1
3444
3999
123444567
123999567

TLE40?
*/
