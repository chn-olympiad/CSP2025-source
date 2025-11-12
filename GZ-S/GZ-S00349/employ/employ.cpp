//GZ-S00349遵义市第十九中学田钦瑞
#include<bits/stdc++.h>
using namespace std;
const int MAXN=998244353;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,ans,sum;
	string s;
	cin>>n>>m;
	int a[n+1],b[n];
	cin>>s;
	ans=s.size();
	for(int i=1;i<=n;i++){
		b[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=s.size();i++){
		if(s[i]==0){
			b[i]=0;
			ans--;
			sum++;
			if(ans==m){
				break;
			}
			if(a[i+1]==sum){
				a[i+1]=false;
				sum=1;
			}		
		}
	} 
	return 0;
} 
