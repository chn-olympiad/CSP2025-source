#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[10005];
	cin>>s;
	long long a[10005],b=0;
	
	for(int i=0;i<=1000;i++){
		if('9'>=s[i]&&s[i]>='0'){
			switch (s[i]) {
			case '9':
				a[b]=9;
				break;
			case '8':
				a[b]=8;
				break;
			case '7':
				a[b]=7;
				break;
			case '6':
				a[b]=6;
				break;
			case '5':
				a[b]=5;
				break;
			case '4':
				a[b]=4;
				break;
			case '3':
				a[b]=3;
				break;
			case '2':
				a[b]=2;
				break;
			case '1':
				a[b]=1;
				break;
			case '0':
				a[b]=0;
				break;
			}
			b++;
		}
	}
//	for(int i=0;i<b;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=0,d;i<b;i++){
		int Max=-1;
		for(int j=0;j<=b;j++){
			if(Max<a[j]){
				Max=a[j];
				d=j;
			}
		}
		cout<<Max;
		a[d]=-1;
	}
//	for(int i=0;i<b;i++){
//		cout<<a[i]<<" ";
//	}
	return 0;
}