#include <bits/stdc++.h>
using namespace std;
int b[10];
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    int s=a.size(),x=0;
    for(int i=0;i<s;i++){
		if(a[i]>='0'&&a[i]<='9'){
			x=a[i]-48;
			b[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]--){
			printf("%d",i);
		}
	}
    return 0;
}
