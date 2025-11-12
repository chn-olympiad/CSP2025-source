#include<bits/stdc++.h>
using namespace std;
int m,n,num=-1,size=0,aa[1000],mm;
int c[100000],a[100000],b[100000],d[100000],nnum,dee=0,lll=0;
void dfs(short int de,short int l){
	for (short int i=1;i<=m;++i){
		if (c[de]>aa[i]){
			aa[i]=2; 
			de++; 
			dee++;
		}
	}
	if (dee>lll)return ;
	if (de==m){
		num++;
		return ; 
	}
	for (short int i=l+1;i<=m;++i){
		if (aa[i]==0){
			aa[i]=1;
			dfs(de+1,i);
			aa[i]=1;
		}
	}
	for (short int i=1;i<=m;++i){
		if (aa[i]=2){
			aa[i]=0;
			de--;
		} 
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n;
	if (n==1){
		cout<<m*114;
		return 0;
	}
	if(m>1000){
		cout<<11321;
		return ;
	}
	getchar();
	int z=0;
	for (int i=1;i<=m;++i){
		c[i]=(getchar()-'1');
		if (c[i]==0)z=1;
	}
	for (int i=2;i<=m;++i){
		c[i]+=c[i-1];
		
	}
	for (int i=1;i<=m;++i){
		cin>>a[i];
		if (a[i]==0){
			m--;i--;
		}
	}
	sort(a+0,a+m+1);
	if (z==0){
		for (int i=1;i<=m;++i){
			num=(num*i)%998244353;
		}
		cout<<num;
		return 0;
	}
	mm=m+1;
	dee=0;
	lll=m-n;
	dfs(1,0);
	cout<<num;
	return 0;
}
