#include<bits/stdc++.h>
using namespace std;
char c;
long long t[10];
int main(){
	freopen("number.out","w",stdout);
	freopen("number.in" ,"r",stdin );
	while(cin>>c){
		if(c<='9' && c>='0'){//ÊÇÊý×Ö
			t[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(t[i]>0){
			for(int j=1;j<=t[i];j++)
				printf("%d",i);
		}
	}
	return 0;
} 
