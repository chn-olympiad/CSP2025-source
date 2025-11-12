#include<bits/stdc++.h>
using namespace std;
int a[4][100005];
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	
	int t,s=0;
	cin>>t;
	for(int p=1;p<=t;p++){
		int n;
		cin>>n;
		for(int q=1;q<=n;q++){
			cin>>a[1][q]>>a[2][q]>>a[3][q];
		}
		for(int i=1;i<=n;i++){
			int maxa=-10000,s2,mb,b[100005];
			for(int j=1;j<=3;j++){
				if(a[j][i]>maxa){
					mb=j;
					maxa=a[j][i];
				}
			}
			for(int j=1;j<=n;j++){
				b[j]=a[mb][j];
			}
			sort(b+1,b+n+1);
			for(int j=n;j>n/2;j--){
				if(a[mb][i]==b[j]){
					s+=a[mb][i];
					break;
				}
			}
		}
		cout<<s;
		s=0;
	}
}
