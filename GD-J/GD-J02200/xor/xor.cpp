#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,m,p,h,cnt=0; 
bool b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		 h=a[i],p=i-1;
		while(h!=m&&b[p]!=1){
		h=h^a[p];
		p--;	
		}
		if(h==m){
		cnt++;
		for(int j=p+1;j<=i;j++)b[j]=1;	
		}
	}
	cout<<cnt;
	return 0;
} 
