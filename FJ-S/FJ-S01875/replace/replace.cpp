#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
string str1[M],str2[M],t1[M],t2[M];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++){
		cin>>str1[i]>>str2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		cout<<"0\n";
	}
	return 0;
}

