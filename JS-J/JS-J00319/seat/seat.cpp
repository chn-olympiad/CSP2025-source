#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++) cin>>a[i];
	if(n==1){
		cout<<n<<" "<<m<<endl;
		return 0;
	}
	if(n==2){
		if(m%2) cout<<m<<" "<<2<<endl;
		else cout<<m<<" "<<1<<endl;
		return 0; 
	}
	int ans=a[0];
	sort(a,a+n*m);
	
	int b[n][m]={0};
	int cnt=-1;
	for(int i=0;i<n;)
		for(int j=0;j<m;){
			b[i][j]=a[++cnt];
			if(j%2)
				if(i!=n-1) i++;
				else j++;
			else
				if(i!=0) i--;
				else j++;
		}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(b[i][j]==ans) cout<<j+1<<" "<<i+1<<endl;
	
	return 0;
}
