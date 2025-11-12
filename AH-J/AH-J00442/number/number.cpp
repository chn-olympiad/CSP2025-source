#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char a[N],b[N];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	int len=strlen(a),j=0;
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[j++]=a[i];
		}
	}
	sort(b,b+j,cmp);
	printf("%s",b);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
