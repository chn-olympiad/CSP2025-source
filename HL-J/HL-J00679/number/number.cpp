#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
int n,b,num[N],i=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin >> a[n++]){
		b=a[n-1];
		if(b>=48&&b<=57){
			num[i]=b-48;
			i++;
		}
	}
	sort(num+1,num+i+1);
	for(int j=i;j>=1;j--){
		cout << num[j];
	}
}
