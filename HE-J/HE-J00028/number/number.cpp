#include<bits/stdc++.h>
using namespace std;
string a;
int b[9999999],x=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0' && a[i]<='9'){
			b[x++]=(a[i]-'0');
		}
	}
	sort(b,b+x,cmp);
	if(b[0]==0){
		cout << "0";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<x;i++){
		cout << b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
