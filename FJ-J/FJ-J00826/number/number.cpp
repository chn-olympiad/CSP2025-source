#include<bits/stdc++.h>
using namespace std;
int n;
long long a[13];
string q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>q;
	for(int i=0;i<q.size();i++){
		if(q[i]>='0'&&q[i]<='9'){
			a[q[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}
