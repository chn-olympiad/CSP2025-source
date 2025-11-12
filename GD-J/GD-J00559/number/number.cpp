#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
int a[maxn],n,len;
char s[maxn]; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
		if(i==1 && a[i]==0){
			break;
		}
	}
	return 0;
}
