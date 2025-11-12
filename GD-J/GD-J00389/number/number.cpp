#include <bits/stdc++.h>
using namespace std;
long long a[10];
char n[1000];
int main()
{
	freopen("fre.in","r",stdin);
	freopen("fre.out","w",stdout);
	for(int i=0;i<=1000;i++){
		n[i]='*';
	}
	cin >> n;
	int num=0;
	for(int i=0;i<=1000;i++){
		if(n[i]!='*')num++; 
	}
	while(num--){
		if(n[num]>='0'&&n[num]<='9') a[n[num]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
} 
