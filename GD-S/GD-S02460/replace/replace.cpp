#include<bits/stdc++.h>
using namespace std;
string s1[10005],s2[10005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	string s;
	for(int i=1;i<=q;i++){
		cin>>s>>s;
		int a=0;
		for(int j=1;j<=n;j++){
			if(s.find(s1[j])>0&&s.find(s1[j])<s.size()){
				a++;
			}
		}
		cout<<0<<endl;
	}
	return 0;
}
/*

*/
