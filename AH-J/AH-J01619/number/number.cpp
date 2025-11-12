#include<bits/stdc++.h>
using namespace std;
char a[100005],b[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a; b[1]='0';
	int l=strlen(a);
	int m=1;
	for(int i=0;i<l;i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[m]=a[i];
			m++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			if(b[i]<b[j]){
				char x=b[i]; b[i]=b[j]; b[j]=x;
			}
		}
		cout<<b[i];
	}
	return 0;
}
