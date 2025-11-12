#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt;
int main(){ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin >> n;
	for(int i=0;i <n.size();i++){
		if('0'<=n[i]&&n[i]<='9'){
			a[cnt]=n[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(int i = cnt-1; i>=0; i--)printf("%d",a[i]);
	return 0;
}

