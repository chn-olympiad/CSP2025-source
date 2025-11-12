#include<bits/stdc++.h>
using namespace std;
long long a[10000001],b[9],c[9],d[9];
long long n,k,cnt;
long long z1(int s){
	long long w=8;
	while(s){
		b[w--]=s%2;
		s/=2;
	}
}
void z2(int s){
	long long w=8;
	while(s){
		c[w--]=s%2;
		s/=2;
	}
}
long long look(int x,int y){
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	if(x==y) return a[x];
	z1(a[x]);
	for(long long i=x+1;i<=y;i++){
		z2(a[i]);
		for(long long j=1;j<=8;j++){
			if(b[j]+c[j]==1) d[j]=1;
			else d[j]=0;
		}
		for(long long j=1;j<=8;j++){
			b[j]=d[j];
		}
	}
	int num=0,flag=1;
	for(long long i=8;i>=1;i--){
		num+=b[i]*flag;flag*=2;
	}return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;long long maxn=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(look(i,j)==k&&j>maxn&&i>maxn){
				cnt++;maxn=j;
			}
		}
	}cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
