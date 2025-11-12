#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10],x;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    	   x=(s[i]-'0');
    	   a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
		   for(long long j=1;j<=a[i];j++){
			   printf("%d",i);
		   }
		}
	}
	printf("\n");
	return 0;
}
