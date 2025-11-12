#include<bits/stdc++.h>
using namespace std;
string a;
long long b[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long z=0;z<=9;z++)b[z]=0;
	for(long long z=0;z<a.length();z++){
		if(a[z]>='0'&&a[z]<='9')b[a[z]-'0']++;
	}
	for(long long z=9;z>=0;z--){
		for(int y=1;y<=b[z];y++)cout<<z;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
