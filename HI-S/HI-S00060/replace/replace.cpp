#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q,ans=0;
int sj1=1;
string s[100005][2],t[100005][2];
ll len(string a1){
	int ai=0;
	while((int)a1[ai]!=0){
		ai++;
	}
	return ai;
}
int rep1(string t1,string t2,string s1,string s2){
	int ti1=0,ti2=0,si1=0,si2=0;
	for(int i=0;i<len(t1);i++){
		if(t1[i]=='b'){
			ti1=i;
			break;
		}
	}
	for(int i=0;i<len(s1);i++){
		if(s1[i]=='b'){
			si1=i;
			break;
		}
	}
	
	for(int i=0,j=ti1-si1;i<len(s1);i++,j++){
		t1[j]=s2[i];
	}
	if(t1==t2)return 1;
	else return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	int an=0,bn=0;
	ans=0;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
		an=0,bn=0;
		for(int j=0;j<len(s[i][0]);j++){
			if(s[i][0][j]=='a')an++;
			else if(s[i][0][j]=='b')bn++;
			if(s[i][1][j]=='a')an++;
			else if(s[i][1][j]=='b')bn++;
		}
		if((an+bn)!=(len(s[i][0])*2)||bn!=2){
			sj1=0;
		}
	}
	for(int i=0;i<q;i++){
		cin>>t[i][0]>>t[i][1];
		an=0,bn=0;
		for(int j=0;j<len(t[i][0]);j++){
			if(t[i][0][j]=='a')an++;
			else if(t[i][0][j]=='b')bn++;
			if(t[i][1][j]=='a')an++;
			else if(t[i][1][j]=='b')bn++;
		}
		if((an+bn)!=(len(t[i][0])*2)||bn!=2){
			sj1=0;
		}
	}
	if(sj1==1){
		for(int i=0;i<q;i++){
			ans=0;
			for(int j=0;j<n;j++){
				ans+=rep1(t[i][0],t[i][1],s[j][0],s[j][1]);
			}
			cout<<ans<<"\n";
		}
	}
	else{
		for(int i=0;i<q;i++)cout<<0<<"\n";
	}
	return 0;
}
