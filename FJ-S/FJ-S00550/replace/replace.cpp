#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q,qw[200100][3];
bool t[1001000];
string s[200100][3],ts1,ts2;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		qw[i][1]=100000000000;
		for(int j=0;j<s[i][1].length();j++){
			if(s[i][1][j]!=s[i][2][j]){
				qw[i][1]=j;
				break;
			}
		}
		for(int j=0;j<s[i][1].length();j++){
			if(s[i][1][j]!=s[i][2][j]){
				qw[i][2]++;
			}
		}
		//cout<<" "<<qw[i][1]<<" "<<qw[i][2]<<endl;
	}
	for(int i=1;i<=q;i++){
		cin>>ts1>>ts2;
		if(ts1.length()!=ts2.length()){
			cout<<0<<endl;
			continue;
		}
		ll jd=ts1.length(),wz,con=0,ans=0;
		for(int i=0;i<jd;i++){
			if(ts1[i]!=ts2[i]){
				wz=i;
				break;
			}
		}
		for(int i=0;i<jd;i++){
			if(ts1[i]!=ts2[i]){
				con++;
			}
		}
		//cout<<" "<<wz<<" "<<con<<" "<<endl;
		for(int i=1;i<=n;i++){
			if(con==qw[i][2]&&wz>=qw[i][1]&&wz-qw[i][1]+s[i][1].length()<=ts1.length()){
				ll pd=1;
				for(int j=wz-qw[i][1];j<wz-qw[i][1]+s[i][1].length();j++){
					if(ts1[j]!=s[i][1][j-(wz-qw[i][1])]||ts2[j]!=s[i][2][j-(wz-qw[i][1])]){
						pd=0;
						break;
					}
				}
				ans+=pd;
			} 
		}
		cout<<ans<<endl;
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
