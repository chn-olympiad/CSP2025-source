#include<bits/stdc++.h>
using namespace std;
string a;long long b[100],j;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
			j++;
		}
	for(int i=9;i>=0;i--){
		if(b[i]) while(b[i]--) printf("%d",i);
		else continue;
	}
	return 0;
}
