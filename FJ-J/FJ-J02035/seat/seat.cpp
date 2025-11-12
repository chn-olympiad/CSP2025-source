#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[111],k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	k=s[1];
	sort(s+1,s+1+n*m,cmp);
	cout<<k<<endl;
	for(int i=1;i<=n*m;i++){
		cout<<s[i]<<' ';
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[j+n*(i-1)]==k){
				if(i%2!=0) cout<<i<<' '<<j;
				else cout<<i<<' '<<n-j+1;
				return 0;
			}
		}
	}
	return 0;
}

