#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int s[18],l;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    l=strlen(a);
    for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){s[int(a[i]-'0')]++;}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=s[i];j++){
		    cout<<i;
		}
	}
    return 0;
}
