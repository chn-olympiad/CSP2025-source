#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const long long MOD=998244353;
int p[505];
int tp=0;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		cout<<p[i]<<" ";
	}
	int su=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			tp++;
		}else if(s[i]=='1'){
			int r=0;
			for(int j=1;j<=n;j++){
				if(p[j]>tp){
					r++;
					cout<<p[j]<<r<<endl;
				}
			}
			su*=r;
		}
	}
	cout<<su;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
