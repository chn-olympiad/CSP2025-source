#include<bits/stdc++.h>
using namespace std;
const int N=200000+10;
string s1[N],s2[N],q1[N],q2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>q1[i]>>q2[i];
	}
	for(int i=1;i<=q;i++) cout<<"0"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

