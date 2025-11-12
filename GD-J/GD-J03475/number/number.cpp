#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int b[1000010];
bool cmp(int n,int m){
	return n>m;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
		cin>>a;
	int j=1;
	for(int i=0;i<=strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[j]=(a[i]-'0');
			j++;
		}
	}
	sort(b+1,b+j+1,cmp);
	for(int i=1;i<j;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
} 
