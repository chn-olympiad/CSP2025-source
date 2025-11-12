#include<bits/stdc++.h>
using namespace std;
typedef long long 11;
int scr[1000];
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int a,b,c;
	cin >> a >> b;
	if(b == 0 && a <= 2){
		cout << 1;
		return 0;
	}
	for(int i = 0;i <= a;i++){
		cin >> ans[i];
	}
	ansq[1] = ans[1];
	for(int i = 2;i <= a;i++){
		ansq[i] = ansq[i-1] + ans[i];
	}
	for(int i=1;i<=a;i++){
		for(int i1=1;i1 <= a;i++)
		flag = 0;
	}
	//fclose(stdin);
	//fclose(stdout);
	cout << sum;
	return 0;
}
	
