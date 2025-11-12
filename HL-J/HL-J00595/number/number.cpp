#include<bits/stdc++.h>
using namespace std;
char n[1000000];
int a[1000000];
int b;
void f(){
	for(int i=1;i <= b;i++) cout << 0;
	exit(0);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	for(int i=0;i < 1000000;i++){
		if(n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '6' || n[i] == '7' || n[i] == '8' || n[i] == '9') a[i]=n[i]-'0';
		if(n[i] == '0') b += 1;
	}
	sort(a,a+1000000,cmp);
	for(int i=0;i < 1000000;i++){
		if(a[i] == 0) f(); 
		cout<<a[i];
	} 
	return 0;
}
