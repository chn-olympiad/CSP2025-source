#include<bits/stdc++.h>
using namespace std;
int c[10];
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            c[a[i]-'0']++;
        }
	}
    for(int i=9;i>=0;i--){
        for(int j=0;j<c[i];j++){
            cout<<i;
        }
    }
	return 0;
}
