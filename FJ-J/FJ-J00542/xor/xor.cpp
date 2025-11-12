#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int b[10001],d[10001][10001],e[10001],ans;
void db(int);
void yhh(int);
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,r=0;
	int a[10001];
	memset(a,0,sizeof(a));
	memset(e,1,sizeof(e));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int h=i;
			for(h=i;h<=j;h++){
				b[h-i]=a[h];
			}
			db(h-i);
			yhh(h-i);
			if(ans==k){
				r++;
			}
		}
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void db(int n){
	for(int i=0;i<n;i++){
		int c[10001],j=0;
		while(b[i]!=0){
			c[j]=b[i]%2;
			b[i]/=2;
			j++;
		}
		for(int g=j;g>=0;g--){
			d[i][e[i]-1]=c[g];
			e[i]++;
		}
	}
}
void yhh(int n){
	for(int i=0;i<n;i++){
		for(int j=e[i];j>=0;j--){
			if((d[i][j]==0&&d[i+1][j]==1)||(d[i][e[i]]==1&&d[i][e[i]+1]==0)){
				ans+=pow(2,j);
			}
		}
	}
}