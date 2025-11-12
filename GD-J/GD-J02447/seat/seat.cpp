#include <bits/stdc++.h>
using namespace std;
int a[110];
int b[16][16];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+k+1,cmp);
	int ans=1;
	int ansa=1;
	for(int q=1;q<=m;q++){
		for(int p=1;p<=n;p++){
			b[ans][q]=a[ansa];
			ansa++;
			if((q%2==1)&&(ans!=n)) ans++;
			if((q%2==0)&&(ans!=1)) ans--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r) cout<<j<<" "<<i;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
