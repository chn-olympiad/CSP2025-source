#include<bits/stdc++.h>
using namespace std;
int n,q,res;
string s1,s2,r;
//bool findd(string s1,string s2){
//	int x,y;
//string r=substr(x,y);
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
		cin>>s1>>s2;
	r=s1-s2;
	if(r.size()<s1.size()) res+=2;
//	for(int i=1;i<=k;i++){
//	for(int j=1;j<=n;j++){
//	x+=c[i];
//	y+=a[i][j];
//}
//}
	
	
	cout<<res;
	return 0;
}
