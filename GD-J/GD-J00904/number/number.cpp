#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;int k=0;
	while(cin.get(c)){
		if (c=='\n') break;
		if (isdigit(c)) a[++k]=c-'0';
	}
	sort(a+1,a+1+k,cmp);
	for (int i=1;i<=k;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
