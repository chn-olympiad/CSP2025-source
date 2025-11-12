#include<bits/stdc++.h>
using namespace std;
int d[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a;
	cin>>a;
	for(int i=0;i<a.size();++i){
        if(a[i]<='9'&&a[i]>='1'){
            d[a[i]-'0']++;
        }
	}
	for(int i=9;i>0;--i){
        for(int j=0;j<d[i];++j){
            cout<<i;
        }
	}
	return 0;
}
