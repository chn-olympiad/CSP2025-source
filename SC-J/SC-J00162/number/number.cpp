#include<bits/stdc++.h>
using namespace std;
int cnt,x[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>=48 and a[i]<=57){
			x[cnt]=(int)a[i]-48;
			cnt++;
		}
	}
	sort(x,x+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<x[i];
	}
	return 0;
}