#include<bits/stdc++.h>
using namespace std;

int n,m,sum,f=1,ans;
int a[15][15],s[105];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>s[i];
	}
	ans=s[1];
	sort(s+1,s+1+sum,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				a[i][j]=s[f];
				f++;
				if(a[i][j]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				a[i][j]=s[f];
				f++;
				if(a[i][j]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	
	
	
	
	//#Shang4Shan3Ruo6Shui4
	
	
	return 0;
}
