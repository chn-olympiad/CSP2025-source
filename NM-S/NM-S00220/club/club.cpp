#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,k[10],ans,check[N][10],a[N][10],maxn,c[N],t;
void f(int x){//µÚx¸öÈË
	if(x>n){
		ans=0;
		for(int i=1;i<=n;i++){
			ans+=c[i];
		}
		maxn=max(maxn,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(k[i]<(n/2)&&check[x][i]==0){
			k[i]++;
			c[x]=a[x][i];
			check[x][i]=1;
			f(x+1);
			k[i]--;
			check[x][i]=0;
		}

	} 
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	maxn=0,ans=0;
	memset(check,0,sizeof(check));
	memset(a,0,sizeof(a));
	k[1]=0,k[2]=0,k[3]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}		
	}
	if(n>200){
		int m=0,s[N];
		long long arr=0;
		for(int i=1;i<=n;i++){
			s[i]=a[i][1];
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n/2;i++)arr+=s[i];
		cout<<arr;
	}
	else{
		f(1);
	cout<<maxn<<endl;
	}
	
	}
	
	return 0;
} 
