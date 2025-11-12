#include<bits/stdc++.h>
using namespace std;
int a[20]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char n[100100];
    cin>>n;
    for(int i=0;i<strlen(n);i++){
		int t=n[i]-48;
        if(t>=0 && t<=9){
			a[t]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
