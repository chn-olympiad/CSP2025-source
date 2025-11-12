#include<bits/stdc++.h>
using namespace std;
string ss;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin>>ss;
	int l=ss.size(),idx=0;
	for(int i=0;i<=l-1;i++){
		if(ss[i]>='0' && ss[i]<='9'){
			int x=ss[i]-'0';
			a[idx++]=x;
		}
	}
	sort(a,a+idx);
	for(int i=idx-1;i>=0;i--){
		printf("%d",a[i]);
	}
	return 0;
}