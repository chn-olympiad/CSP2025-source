#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,q;
string s[200010][3],s1,s2;
int check(int x){
	int sum=0;
//	cout<<x<<"\n";
	for(int l=0;l<=s1.size()-s[x][1].size();l++){
		int f=1;
		for(int r=l;r<l+s[x][1].size();r++){
			if(s1[r]!=s[x][1][r-l]){
				f=0;
				break;
			}
		}
		if(f==0) continue;
//		cout<<l<<" ";
		string s3=s1;
		for(int r=l;r<l+s[x][1].size();r++){
			s3[r]=s[x][2][r-l];
		}
		if(s3==s2) sum++;
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	} 
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		int sum=0;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		} 
		for(int j=1;j<=n;j++){
			if(s[j][1].size()>s1.size()) continue;
			int k=check(j);
			sum+=k;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
