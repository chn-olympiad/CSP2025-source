#include<bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
#define ll long long
int n,q;
string s[200005][2];
string t[200005][2];
struct node{
	char c;
	int son[26];
}tr[2000005];
int sum;
void insert(string s){
	int now=0;
	for(auto i:s){
		if(!tr[now].son[i-'a']){
			sum++;
			tr[now].son[i-'a']=sum;
		}
		now=tr[now].son[i-'a'];
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=q;i++){
		int ans=0;
		if(t[i][0].length()!=t[i][1].length()){
			cout<<"0\n";
			continue;
		}
		int l=0,r=t[i][0].length()-1;
		for(;l<t[i][0].length();l++)
			if(t[i][0][l]!=t[i][1][l])break;
		for(;r>=0;r--)
			if(t[i][0][r]!=t[i][1][r])break;
		if(r==0&&t[i][0][r]==t[i][1][r]){
			cout<<"0\n";
			continue;
		}
		string str=t[i][0].substr(l,r-l+1),_str=t[i][1].substr(l,r-l+1);
//		cout<<l<<" "<<r<<" "<<str<<"\n";
		for(int j=1;j<=n;j++){
//			cout<<s[j][0]<<" "<<t[i][0]<<" "<<s[j][0].find(str)<<"\n";
			if(
				s[j][0].find(str)<s[j][0].length()&&
				t[i][0].find(s[j][0])<t[i][0].length()&&
				s[j][1].find(_str)<s[j][1].length()&&
				t[i][1].find(s[j][1])<t[i][1].length()
			){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

/*
À¶~×Ï 
AC×Ô¶¯»ú
AC-rho 
*/

