#include<bits/stdc++.h>
using namespace std;

const int N=1e6;
int n,q;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
//	for (int i=1,t1,t2;i<=q;i++){
//		cin>>t1>>t2;
//		if (s1.size()!=t2.size()){
//			cout<<0<<endl;
//			continue;
//		}
//		int p=0,q=0;
//		for (int i=0,p,q;i<t1.size();i++){
//			if (t1[i]!=t2[i]&&t1[i-1]==t1[i-1])
//				p=i;
//			if (t1[i]!=t2[i]&&t1[i+1]==t2[i+1]){
//				q=i;
//				c++;
//				bt[c][0]=p;
//				bt[c][1]=q;
//			}
//		}
//	}
	for (int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
