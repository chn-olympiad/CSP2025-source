#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long cnt=0,b[100001];
	for(int i=0;i<a.size();i++){
		if((long long)a[i]>=48&&(long long)a[i]<=57){
			b[cnt]=a[i]-48;
			cnt++;
		}
	}
	sort(b,b+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
