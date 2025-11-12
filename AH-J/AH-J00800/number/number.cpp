#include<bits/stdc++.h>
using namespace std;
long long q[20],e;
string w;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>w;
	e=w.size();
	for(int i=0;i<e;i++){
		if(w[i]>='0'&&w[i]<='9'){
			q[int(w[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<q[i];j++){
			cout<<i;
		}
	}
	return 0;
}
