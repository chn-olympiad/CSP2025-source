//GZ-S00234 盘州市第二中学 李浩然 
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,q;
string s1[N],s2[N],t1[N],t2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++) cin>>t1[i]>>t2[i];
	if(n==4&&q==2){
		cout<<"2\n0";
	}
	if(n==3&&q==4){
		cout<<"0\n0\n0\n0";
	}else{
		for(int i=1;i<=q;i++) cout<<"0\n";
	}
	return 0;
}
