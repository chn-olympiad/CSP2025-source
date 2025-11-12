#include<bits/stdc++.h>
using namespace std;
//#define int long long

const int N=1e6+10;

char s;
int a[N],cnt,st=1;

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&s)!=EOF){
		if('0'<=s&&s<='9'){
			a[++cnt]=s-'0';
		}
	}
	
	if(cnt==1){
		printf("%d",a[1]);
		return 0;
	}
	
	sort(a+1,a+cnt+1,cmp);
	while(a[st]==0)st++;
	for(int i=st;i<=cnt;i++)printf("%d",a[i]);
	return 0;
}
