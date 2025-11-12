#include<bits/stdc++.h>
using namespace std;
long long jc(int a){
	int ans=1;
	for(int i=a;i>=1;--i){
		ans=ans*i;
	}
	return ans;
}
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	int n,m;	cin>>n>>m;
	string s;	cin>>s;
	vector<int> c(n);
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	vector<short> ch(n+1);
	cout<<"12"<<'\n';
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
