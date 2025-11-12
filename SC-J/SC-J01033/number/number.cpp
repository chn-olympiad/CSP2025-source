#include<bits/stdc++.h>
using namespace std;
int a[1001006],cnt;
string l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>l;
	for(int i=0;i<l.size();i++){
		if('0'<=l[i]&&l[i]<='9'){
			a[++cnt]=l[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}