#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int s = 0;
	int b[99999] = {0};
	for(long long i=0;i<a.size();i++){
		long long c = a[i]-'0';
		if (c<=9&&c>=0){
			b[s] = c;
			s+=1;
			
		}
	}
	int m[99999]={};
	int d = 0;
	int max = 0;
	for(long long i = 0;i<s;i++){
		int max = 0;
		for(long long j = 0;j<s;j++){
			if (b[j]>=max){
				max = b[j];
			}
		}
		for(long long l = 0;l<s;l++){
			if(b[l] == max){
				b[l] = -1;
				break;
			}
		}
		m[i] = max;
		d+=1;
		cout<<m[i];
	}
//	for(int i = 0;i<d;i++){
//		cout<<m[i];
//	}

return 0;
}
