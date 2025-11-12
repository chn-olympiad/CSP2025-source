#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a;
	cin>>a;
	int s[105]={0};
	s[1]=a;
	for(int i=2;i<=m*n;i++){
		cin>>s[i];
	}
	int c;
	int d;
	for(int i=1;i<=n*m+1;i++){
		for(int q=1;q<=i;q++){
			c=max(s[q],s[q+1]);
			d=min(s[q],s[q+1]);
			s[q]=c;
			s[q+1]=d;
		}
	}
	int x[n+3][m+3];
	int w=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			x[i][j]=s[w];
			w++;
		}
	}
	int h;
	int l;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i][j]==a){
				h=i;
				l=j;
			}
		}
	}
	if(h%2==1){
		cout<<h<<' '<<l;
	}else{
		cout<<h<<' '<<m-l+1;
	}
	return 0;
}
