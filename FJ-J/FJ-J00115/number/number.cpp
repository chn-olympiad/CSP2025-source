#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if('0'<=a[i]&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
/*
priority_queue<int> q;
bool operator<(SS x)
*/
