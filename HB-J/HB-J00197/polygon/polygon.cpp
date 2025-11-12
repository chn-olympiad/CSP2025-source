#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int n,a[500001],b[50001],c[50001],t,s;
long long h,s1;

void pr(int x){
	h=0;
	for(int i=1;i<=x;i++) h+=c[a[i]];
	if(h!=s1) {if(h>2*c[a[x]]) t++; }
	//cout<<h<<" ";
	s1=h;
	//cout<<t<<endl;
	
}

void dfs(int i){
	int j;
	for(j=1;j<=n;j++){
		if(a[j-1]<j&&b[j]==0){
				a[i]=j;
				b[j]=1;
				if(i>=3) {pr(i);}
				dfs(i+1);
				b[i]=0;
				//b[i]=0;
				//continue;
			}
			
		}
	}

int main(){
	cin>>n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++)
	cin>>c[i];
	dfs(1);
	cout<<t;
	return 0;
}
