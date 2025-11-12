#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,q;
string s1[100002],s2[100002],t1,t2;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		cout<<n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
