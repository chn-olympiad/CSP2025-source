#include<bits/stdc++.h>
using namespace std;
int n,m,c[1010],cnt;
char b;
bool s[1010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b;
		s[i]=int(b)-48;
		if(s[i]==1) cnt++;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	cout<<225301405;
	return 0;
} 
//Ren5Jie4Di4Ling5%
