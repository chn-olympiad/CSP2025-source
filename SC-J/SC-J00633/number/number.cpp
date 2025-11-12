#include<bits/stdc++.h>
using namespace std;
string a;
int b[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
			}
	for(int i=9;i>=0;i--){
	while(b[i]>0){
		cout<<i;
			b[i]--;
		}
			}
	
	return 0;
} 