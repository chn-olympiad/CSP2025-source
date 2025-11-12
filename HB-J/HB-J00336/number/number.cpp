#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b[15],cnt=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	while(a){
		b[cnt]=a%10;
		a%=10;
		cnt++;
	}
	for(int i=0;i<cnt;i++){
		if(b[i]<b[i+1]){
			swap(b[i],b[i+1]);
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<b[i];
	}
	return 0;
}
