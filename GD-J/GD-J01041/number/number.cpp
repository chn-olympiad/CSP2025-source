#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bool cmp(int x,int y){
	return x>y;
}
char s[N];
int cnt,a[N],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		int tmp=s[i]-'0';
		if(tmp>=0&&tmp<=9){
			a[++cnt]=tmp;
		}
	} 
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		printf("%d",a[i]);
	} 
} 
