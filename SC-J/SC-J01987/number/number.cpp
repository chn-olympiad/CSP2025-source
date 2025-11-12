#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string a;
int c[N],q[N],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9' && a[i]>='0'){
			n++;
			c[n]=a[i]-'0';
		}
	}
	for(int i=1;i<=n;i++){
		q[c[i]]++;
	}
	for(int i=9;i>=0;i--){
		while(q[i]>0){
			cout<<i;
			q[i]--;
		}
	}
	return 0;
}