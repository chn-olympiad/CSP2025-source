#include<bits/stdc++.h>
using namespace std;
long long c[300005],b[300005],x,x1,y,n,m,s[300005],q=1,p=1;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			y++;
			for(int j=1;j<=n;j++){
				if(c[j]>y&&c[j]!=0&&j!=n&&i<m){
					x1++;
					b[i]=j;
					c[j]=0;
					break;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(c[j]!=0&&j!=n&&i<m){
					c[j]=0;
					x++;
					break;
				}
			}
		}
	}
	for(int p=1;p<=n-x-x1;p++){
		q=p*q%998244353;
	}
	cout<<q;
	return 0;
}
