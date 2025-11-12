#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	string s="abcd";
//	cout<<s.replace(1,1,"e")<<endl;
//	cout<<s<<endl;
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	string t1,t2;
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			long long x1=(int)t1.find(s1[i]);
			long long x2=(int)t2.find(s2[i]);
			string y=t1;
			if(x1<t1.size()&&x2<t2.size()){
			   	if(y.replace(x1,s2[i].size(),s2[i])==t2)ans++;
			}
//			cout<<"x1="<<x1<<" x2="<<x2<<" ";
//			cout<<"t1="<<y<<" t2="<<t2<<" ";
//			cout<<endl;
		}
		printf("%d\n",ans);
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
2
0

3 4
a b
b c
c d
aa bb
aa b
a c
b a
0
0
0
0

*/
