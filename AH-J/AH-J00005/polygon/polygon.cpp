#include<bits/stdc++.h>
using namespace std;
const long long mo=998244353;
long long n,a[10005],b[10005],s=0;
int query(long long m,long long a[]){
	int flag=0;
	long long s=0,maxn=0;
	if(m>=3)flag++;
	for(int i=1;i<=m;i++){
		s+=a[i];
		if(a[i]>maxn)maxn=a[i];
	}
	if(s>2*maxn)flag++;
	if(flag==2)return 1;
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		cout<<query(3,a);
	}
	else{
		long long aa=1;
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n-i;j++){
				aa=1;
				memset(b,0,sizeof(b));
				for(int k=j;k<=j+i-1;k++){
					b[aa++]=a[k];
				}
				if(query(i,b))s++;
			}
		}
		cout<<s%mo;
	}
return 0;
}

