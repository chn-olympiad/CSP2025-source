#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],k = 0;

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0;i < len;i++){
		if(s[i] >= '0'&& s[i] <= '9'){
			a[k] =  s[i] - '0';
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(int i = 0;i < k;i++){
		printf("%lld",a[i]);
	}
	return 0;
}
