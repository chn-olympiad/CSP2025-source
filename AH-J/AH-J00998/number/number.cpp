#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int cnt=0,b[1010];
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			cnt++;
			b[cnt]=a[i]-'0';
		}
	}
	sort(b+1,b+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}
