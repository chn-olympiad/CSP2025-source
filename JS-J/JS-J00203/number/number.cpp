#include<bits/stdc++.h>
using namespace std;
char a[1000009];
int b[1000009];
int main(){
    freopen("number4.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int num=0;
	cin>>a;
	for(int i=0;a[i];++i){
        if(a[i]>='0' && a[i]<='9'){
            b[num++]=a[i]-'0';
        }
	}
	sort(b,b+num);
	for(int i=num-1;i>=0;--i){
        cout<<b[i];
	}
	return 0;
}
