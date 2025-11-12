#include<bits/stdc++.h>
using namespace std;
int cnt=0;
string a="1",n[1000005]="1";
int l(string a){
	int cnt=0;
	for(int i=0;;i++){
		if((a[i]>='a' && a[i]<='z')||(a[i]<='9' && a[i]>='0'))cnt++;
		else return cnt;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<l(a);i++){
		char x;
		x=a[i];
		if(x<='9' && x>='0'){
			n[cnt]=x;
			cnt++;
		}
	}
	sort(n,n+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
} 


