#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1001][1001],c[10001],b[10001],x,num=1,ans=0;
int main(){
	int q=1;
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=n*m;i++) cin>>c[i];
	ans=c[1];
	sort(c+1,c+x+1);
	for(int i=x;i>=1;i--){
		b[q]=c[i];
		q++;
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
			    a[j][i]=b[num];
			    num++;
		    }
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
			    a[j][i]=b[num];
			    num++;
		    }
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==ans){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}