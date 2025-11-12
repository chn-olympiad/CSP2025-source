#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n,q,ans=0;
string a[N],b[N];
string s1,s2,temp;

bool check(int star,int id){
	bool x=1;
	for(int i=1;i<=a[id].size()-1&&x;i++) x&=(s1[star+i-1]==a[id][i]);
	for(int i=1;i<star&&x;i++) x&=(s1[i]==s2[i]);
	for(int i=1;i<=b[id].size()-1&&x;i++) x&=(s2[star+i-1]==b[id][i]);
	for(int i=star+b[id].size()-1;i<=s1.size()-1&&x;i++) x&=(s1[i]==s2[i]);
	return x;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace2.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i] , a[i]=' '+a[i] , b[i]=' '+b[i];
//	q = 1;
	while(q--){
		ans = 0;
		cin>>s1>>s2 , s1=' '+s1 , s2=' '+s2;
//		cout<<a[3]<<endl;
//		cout<<check(3,3)<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=s1.size()-a[i].size()+1;j++) ans+=check(j,i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
