#include<bits/stdc++.h>
using namespace std;
struct sm{
	string s3,s4;
	int m;
}s1[2000005];
string s2[2000005];
string s5[2000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		long long ans=0;
		cin>>s1[i].s3>>si[i].s4;
		int d,e;
		for(int j=1;j<=s1[i].s3.length();j++){
			if(s1[i].s3[j]=='b'){
				d=j;
				break;
			}
		}
		for(int j=1;j<=s1[i].s4.length();j++){
			if(s1[i].s4[j]=='b'){
				e=j;
				break;
			}
		}
		s1[i].m=d-e;
	}
	for(int i=1;i<=q;i++){
		cin>>s2[i]>>s5[i];
		int d,e;
		for(int j=1;j<=s2.length();j++){
			if(s2[i][j]=='b'){
				d=j;
				break;
			}
		}
		for(int j=1;j<=s5.length();j++){
			if(s5[i][j]=='b'){
				e=j;
				break;
			}
		}
		int m1=d-e;
		for(int j=1;j<=n;j++){
			if(s[j].m==m1){
				ans++;
			}
		}
		cout<<ans<<endl
	}
	return 0;
}
