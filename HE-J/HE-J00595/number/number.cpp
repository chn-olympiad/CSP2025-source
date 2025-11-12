#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r","stdin");
freopen("number.out","w","stdout");
char s;
int maxn=-1000;
cin>>s;
for(int i=1;i<=s;i++){
	if('0'<i<'9'){
		for(int j=1;j<=i;j++){
			if(j>maxn){
				maxn=j;
			}
		}
	}
}
cout<<maxn;
return 0;
}
