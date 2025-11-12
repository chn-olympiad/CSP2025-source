#include<bits/stdc++.h>
using namespace std;
string k;
int g[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>k;
    int len = k.size();
    for(int i=0;i<len;i++){
        if(k[i]>='0'&&k[i]<='9'){
			g[k[i]-'0'] +=1;
        }
    }
	for(int i=9;i>=0;i--){
		//cout<<i<<":"<<g[i]<<"\n";
		for(int j=1;j<=g[i];j++){
			cout<<i;
		}
	}
    return 0;
}
