#include<bits/stdc++.h>
using namespace std;
char r;
int a[11],z;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>r)if(r>='0'&&r<='9')a[r-'0']++;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
