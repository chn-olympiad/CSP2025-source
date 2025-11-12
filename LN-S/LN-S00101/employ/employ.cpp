#include<bits/stdc++.h>
using namespace std;
struct num{
	int id;
	int c;
	bool operator<(const num t)const{
		return id<t.id;
	}
};
int n,m;
char s[501];
num a[501];
num b[501];
long long sum,cnt,reduce;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",&s);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].c);
		b[i].c=a[i].c;
		b[i].id=a[i].id=i;
	}
	bool flag=1;
	do{
		sum=reduce=0;
		for(int i=0;i<n;i++){
			if(s[i]-'0'==1&&a[i].c-reduce>0){
				sum++;
				sum%=998244353;
			}
			else reduce++,flag=0;
		}
		if(flag) break;
		if(sum>=m){
			cnt++;
		};
	}while(next_permutation(a,a+n));
	if(flag){
		cnt=1;
		for(int i=2;i<=n;i++){
			cnt*=i;
			cnt%=998244353;
		}
	}
	printf("%lld",cnt);
	return 0;
}
