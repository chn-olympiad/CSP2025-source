#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int c[100005];
int p[1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ.txt","w",stderr);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=i;
	}
	int cnt=0;
	do{
		int C=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				C++;
				continue;
			}
			if(C>=c[p[i]]){
				C++;
				continue;
			}
			sum++;
		}
		if(sum>=m){
			cnt++;
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<cnt<<"\n";
	return 0;
}
/*
这里是T4. 
原来你从未离去，默默守护在这里，无声无息，如影随形。 
*/
