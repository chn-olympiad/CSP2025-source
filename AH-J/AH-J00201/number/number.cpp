#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=1;
	int u=s.size();
	for(int i=0;i<u;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt);
	for(int i=cnt-1;i>=1;i--){
		printf("%d",a[i]);
		if(i==(cnt-1)&&a[i]==0)break;
	}
	printf("\n");
	return 0;
}
