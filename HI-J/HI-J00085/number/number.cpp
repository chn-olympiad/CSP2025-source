#include<bits/stdc++.h>
using namespace std;
int f[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			f[(a[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(f[i]>0){
			f[i]--;
			printf("%d",i);
		}
	}
	
	return 0;
}
