#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n,m;
int a[N];
int grade,key;
bool cmp(int a,int b) {
	return a>b;
}
bool isprime(int n) {
	if(n%2 == 0)
		return true;
	else
		return false;
}
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	cin>>n>>m;
	int len = n*m;
	for(int i=0; i<len; i++)
		cin>>a[i];
	grade = a[0];

	sort(a,a+len,cmp);

	for(int i=0;i<len;i++){
		if(a[i] == grade){
			key = i;
			break;
		}
	}//find xiabiao

	int x = int(key/m)+1;
	int y;
	if(!isprime(m))
		y = key%m;
	else
		y = n-(key%m);
	cout<<x<<" "<<y;
	return 0;
}
