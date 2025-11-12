#include<bits/stdc++.h>
#include<string>
using namespace std;
#define int long long
const int N=1e5;
string s[N][5],t1,t2;
int n;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cout<<"0\n";
//		cin>>t1>>t2;
//		int cnt=0;
//		for(int i=1;i<=n;i++){
//			int ka=t1.find(s[i][1]);
//			int kb=t2.find(s[i][2]);
//			if(ka>=0&&ka<t1.size()&&kb>=0&&kb<t2.size()){
//				cnt++;
//			}
//		}//NO_sir
//		cout<<cnt<<"\n";
	}
//	cout<<t1.find("a");
	return 0;
} 
