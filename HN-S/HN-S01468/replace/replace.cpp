#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,m;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	} 
	for(int i=1;i<=m;i++){
		string s3,s4;
		cin>>s3>>s4;
		for(int j=1;j<=n;j++){
			if(s1[i][j]==s3[j]){
			s1[i][j]=s4[j];
				}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<"0\n";
	}
	return 0;
}
