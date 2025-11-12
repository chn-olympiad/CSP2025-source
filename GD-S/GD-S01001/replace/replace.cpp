#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
string s3[N],s4[N];
int n,m;
string a,b;
int ans=0;
void sol(){
	string l;
	for(int i =1;i<a.size();i++){
		for(int j = i;j<a.size();j++){
			for(int k = i;k<=j;k++){
				l+=a[k];
			}
			for(int k = 1;k<=n;k++){
				if(l==s1[k]){
					string op=s3[i-1]+s2[k]+s4[j+1];
					if(op==b){
						ans++;
					}
				}
			}
			
			l="";
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	

	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	
	
	while(m--){
		cin>>a>>b;
		a=" "+a; 
		for(int i = 1;i<a.size();i++){
			s3[i]=s3[i-1]+a[i];
		}
		for(int i = a.size()-1;i>=1;i--){
			s4[i]=s4[i+1]+a[i];
		}
		sol();
		cout<<ans<<'\n';
		ans=0;
		for(int i = 1;i<a.size();i++)s3[i]="";
		for(int i = 1;i<a.size();i++)s4[i]="";
	}
	return 0;
}
