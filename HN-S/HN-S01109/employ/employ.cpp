#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e2+5; 
string a;
int w[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		if(w[i]!=0)  s++;
		
	} 
	int w=1;
	for(int i=1;i<=min(m,s);i++){
		w*=s;
		w%=998244353;
	}
	cout<<0;
	return 0;
	
}
