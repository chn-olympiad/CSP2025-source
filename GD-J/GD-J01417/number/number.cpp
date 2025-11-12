#include<iostream>
#include<algorithm>
#include<cstring> 
using namespace std;
char a[1000010],b[1000010];
int len,cnt;
bool cmp(const char&a,const char&b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	len=strlen(a);
	for(int i=0;i<len;i++){
		if('0'<=a[i]&&a[i]<='9')b[cnt++]=a[i];
	}
	sort(b,b+cnt,cmp);
	cout<<b;
	return 0;
}
