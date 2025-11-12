#include<bits/stdc++.h>
using namespace std;
const long long N=5e6+10;
long long n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		long long cnt=0;
		string t1,t2;
		cin>>t1>>t2;
		long long l1=((long long)t1.size());
		for(long long i=1;i<=n;i++){
			bool flag=false;
			long long li=((long long)s1[i].size());
			for(long long j=0;j<l1;j++){
				if((j+li-1)<l1&&t1.substr(j,j+li-1)==s1[i]&&t2.substr(j,j+li-1)==s2[i]){
					j=j+li-1;
				}
				else{
					if(t1[j]!=t2[j]){
						flag=false;
					}
				}
			}
			if(flag) cnt++;
		}
		cout<<cnt<<endl;
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
