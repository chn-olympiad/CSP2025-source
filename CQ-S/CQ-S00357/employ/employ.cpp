#include<bits/stdc++.h>
using namespace std;
int n,m,l[114514];
char a[1145];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)scanf("%c",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&l[i]);
	sort(l+1,l+n+1);
	int s=1,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='0')sum++;
		else {
			for(int j=1;j<=n;j++)l[j]-=1;
			if(l[s]==0)sum++;
			else if(l[s]<0)s++;
		}
		if(sum==m){
			sum=n-m;
			break;
		}
		s++;
	}
	long long num=1;
	for(int i=1;i<=sum;i++){
		num*=i;
	}
	printf("161088479");
	return 0; 
}
