#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
string s;
/*
 * Food is delicious.
USA is a country.
Can you swim?
Kate is so big.
,
China is good.
Computer is rubbish.
Fuck CCF!!!
!!!*/
int a[N],num=1;
bool cmp(int x,int y){
	return x>=y;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[num]=s[i]-'0';
			num++;
		}
	}
	num--;
	bool bl=true;
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(bl==true && a[i]==0){
			continue;
		}
		if(a[i]!=0){
			bl=false;
		}
		cout << a[i];
	}
	if(bl==true){
		cout << 0;
	}
	return 0;
}
