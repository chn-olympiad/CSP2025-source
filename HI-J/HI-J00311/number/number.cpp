#include<bits/stdc++.h>
using namespace std;
const int A1=1000009;
int a[A1],a1,a2,a3,a4,a5;
string aa;
bool A2(int c1,int c2){
	return c1>c2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>aa;
	for(int b1=0;b1<aa.size();b1++){
		if(aa[b1]>='0' and aa[b1]<='9'){
			a[++a2]=aa[b1]-'0';
		}
	}
	sort(a+1,a+a2+1,A2);
	for(int b1=1;b1<=a2;b1++){
		printf("%d",a[b1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
