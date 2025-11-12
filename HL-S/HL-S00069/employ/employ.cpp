#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,q;
	cin>>n>>q;
	vector<string> s1(n+1),s2(n+1);//,s3{q+1},s4(q+1);
	string s3,s4; 
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>s3>>s4;
		int ans=0;
		//cout<<s3.substr(1,s3.length()-1);
		for(int j=1;j<=n;j++){
		    int x=s3.find(s1[j]);
		    if(s3.substr(0,x-1)+s1[j]+s3.substr(x+s1[j].size(),s3.size()-(x+s1[j].size()))==s4){
		    ans++;	
			}
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
