#include<bits/stdc++.h>
using namespace std;
char a;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=0;
	while(cin>>a){	
		if('0'<=a&&a<='9'){
			i++;
			b[i]=a-'0';
		}
	}
	sort(b+1,b+1+i);
	for(int j=i;j>=1;j--){
		cout<<b[j];
	}
	return 0;
} 
