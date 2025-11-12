#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,ans;
string s;
int c[N],id[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s,s="0"+s;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]),id[i]=i;
	do{
		int gs=0,q=0;
		for(int i=1;i<=n;i++){
			if(q>=c[id[i]]){q++;continue;}
			if(s[i]=='0') q++;
			else gs++;
		}
		if(gs>=m) ans++;
	}while(next_permutation(id+1,id+1+n));
	cout<<ans;
	return 0;
}
