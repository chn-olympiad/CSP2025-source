#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int a[500005];
int x[5005][5005];
int p[5005][2];
int n,k;
int findd(int x,int s){
	for(int i=0;i<s;i++){
		if(x==p[i][0]) {
			p[i][0]=-1;
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		x[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			x[i][j]=x[i][j-1]^a[j];
		}
	}
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(x[i][j]==k){
				p[s][0]=i;
				p[s][1]=j;
				s++;
			 }
		}
	}
	for(int i=0;i<s;i++){
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int xs=findd(i,s);
		if(xs!=-1){
			ans++;
			i=p[xs][1]-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
