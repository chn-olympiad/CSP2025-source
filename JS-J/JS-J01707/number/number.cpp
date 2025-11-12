#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1999999];
	scanf("%s",s+1);
	int len=strlen(s+1);
	vector<int>a(len+1,0),b(len+1,0);
	for(int i=1;i<=len;i++)
		a[i]=s[i]-'0';
	int j=0;
	for(int i=1;i<=len;i++){
		if(a[i]>=0&&a[i]<=9){
			j++;
			b[j]=a[i];
		}
	}
	for(int i=1;i<=j-1;i++){
		for(int k=i+1;k<=j;k++){
			if(b[i]<=b[k]){
				int t=b[i];
				b[i]=b[k];
				b[k]=t;
			}
		}
	}
	for(int i=1;i<=j;i++){
		printf("%d",b[i]);
	}
	return 0;
}
