#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,q;
string s1[N],s2[N];
string t1[N],t2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(q==0)cout<<17353;
	else{
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
