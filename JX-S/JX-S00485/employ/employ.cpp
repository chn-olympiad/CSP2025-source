#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=100005;
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int n,m,s[N];
	char S;
	cin>>n>>m;
	while(cin>>S){
		int i=1;
		s[i]=S-'0';
		i++;
	}
	int l=strlen(S);
	cout<<l<<endl;
	for(int i=1;i<=l;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
	
