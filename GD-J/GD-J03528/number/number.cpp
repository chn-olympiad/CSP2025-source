#include<bits/stdc++.h> 
using namespace std;
//deque;seat
//vetor;
string a;
long long b[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long o=0;o<b[i];o++){
			printf("%lld",i);
		}
	}
	return 0;
}
