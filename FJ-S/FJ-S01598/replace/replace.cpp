#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,sum;
string s1[N],s2[N];
string t1,t2;
void pi(string a,string b,string c,string d){
	if(c.find(a)==d.find(b)){
		cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
		sum++;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i,j;
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		sum=0;
		cin>>t1>>t2;
		for(j=1;j<=n;j++){
			pi(s1[j],s2[j],t1,t2);
		}
		cout<<sum<<endl;
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
