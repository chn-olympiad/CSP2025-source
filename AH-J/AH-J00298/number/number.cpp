#include<bits/stdc++.h>
using namespace std;
//why the projects are diffcult ?
int b[1000000];
int cc(string a){
	int i=0;
	while(a[i]){
		i++;
	}return i;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int cnt=0;
    cin>>a;
    for(int i=0;i<cc(a);i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			b[cnt]=a[i]-'0';
			cnt++;
		}
	}
	sort(b,b+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
