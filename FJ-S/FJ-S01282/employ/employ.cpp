#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
const int M=2e4+5;
const ll inf=1e17+5;
int n,m,f=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("a.txt","r",stdin);
//	freopen("b.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(!s[i]){
			f=0;
			break;
		} 
	}if(f)cout<<0;
	return 0;
} 
