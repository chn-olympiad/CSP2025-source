#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+10;
void out(int n,int m){
	printf("%d %d",n,m);
	exit(0);
}
int n,m,a[N],tmp,s[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
	}	
	tmp=a[1];
	sort(a+1,a+1+(n*m));
	bool b=1;
	int ans=(n*m)+1;
	for(int i=1;i<=m;i++){
		if(b){
			for(int j=1;j<=n;j++){
				ans--;
				s[j][i]=a[ans];	
				//cout<<s[j][i]<<":"<<j<<" "<<i<<"\n";
			}
		}else{
			for(int j=n;j>=1;j--){
				ans--;
				s[j][i]=a[ans];
				//cout<<s[j][i]<<":"<<j<<" "<<i<<"\n";
			}
		}
		b=(!b);
	}
	
	//cout<<tmp<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<i<<" "<<j<<":"<<s[i][j]<<"\n";
			if(s[i][j]==tmp){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 