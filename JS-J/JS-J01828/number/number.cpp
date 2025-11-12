#include<bits/stdc++.h>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[1000005],num=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){b[num]=a[i]-'0';num++;}}
	sort(b,b+num);
	for(int i=num-1;i>=0;i--){cout<<b[i];}
    return 0;
}
