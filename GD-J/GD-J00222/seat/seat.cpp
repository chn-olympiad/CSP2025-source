#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,s[104];
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&s[i]);
	int tmp=s[1];
	sort(s+1,s+n*m+1,cmp);
	int c=1,r=1,cnt=1;
	while(s[cnt]!=tmp){
		if(c%2){
			if(r<n) r++;
			else c++;
		}
		else{
			if(r>1) r--;
			else c++;
		}
		cnt++;
	}
	printf("%d %d",c,r);
	return 0;
}
