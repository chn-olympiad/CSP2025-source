#include<bits/stdc++.h>
using namespace std;
int n,q,v[5000005];
string s[200005][3],a,b;
long long f;
void c(int x){
	if(x==n){
		if(a==b){
			f++;
		}
		return;
	}
	c(x+1);
	for(int i=0;i<a.size();i++){
		int e=0;
		for(int j=0;j<s[x][0].size();j++){
			if(a[i+j]!=s[x][0][j]||v[i+j]==1){
				e=1;
				break;
			}
		}
		if(e==0){
			string aa=a;
			for(int j=0;j<s[x][0].size();j++){
				a[i+j]=s[x][1][j];
				v[i+j]=1;
			}
			c(x+1);
			a=aa;
			for(int j=0;j<s[x][0].size();j++){
				v[i+j]=0;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=0;i<q;i++){
		cin>>a>>b;
		f=0;
		c(0);
		cout<<f<<endl;
	}
	return 0;
} 

