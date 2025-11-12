#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=505;
int n,sum[N],a[N],x,ma;
char ch;
int main(){
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		scanf("%c",&ch);
		sum[i]+=sum[i-1];
		if(ch=='0')sum[i]++;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]++,ma=max(ma,x);
	}
	for(int i=ma;i>=0;i--)a[i]+=a[i+1];
	for(int i=1;i<=n;i++){
		
	}
	return 0;
}
/*
3 2
101
1 1 2
*/
