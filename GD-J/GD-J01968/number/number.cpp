#include<bits/stdc++.h>
using namespace std;
string z;
int v[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>z;
	for(int i=0;i<z.size();i++){
		if(z[i]>='0'&&z[i]<='9'){
			cnt++;
			v[cnt]=z[i]-'0';
		}
	}
	sort(v+1,v+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<v[i];
	}
}
