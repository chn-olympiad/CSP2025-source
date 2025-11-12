#include<bits/stdc++.h>
using namespace std;
unsigned long long a[100001][100001][100001],c[100001][100001][100001],b,t,m,n,s=0;
string p;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>b;
	for(int i=1;i<=b;i++){
		for(int i=1;i<=b;i++){
			for(int j=1;j<=b;j++){
					cin>>a[i][j][k];					
					t=i;
					m=j;
					n=k;
			}
		}
	}
	if(t<m){
		t=m;
	}
	if(t<n){
		t=n;
	}
	t=0;
	s+=t;
	t=0;
	cout<<s;
return 0;
}
