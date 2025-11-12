#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int num[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	int c=strlen(a);
	for(int i=0;i<c;i++){
		if(a[i]>='0'&&a[i]<='9'){
			num[cnt]=a[i]-'0';
			cnt++;
		}
	}
	sort(num,num+cnt);
	for(int i=cnt-1;i>=0;i--){
		printf("%d",num[i]);
	}
	return 0;
}