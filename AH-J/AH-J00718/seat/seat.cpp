#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m;
struct node{
	ll ex;
	ll id;
}a[N];
bool cmp(node x,node y){
	return x.ex>=y.ex;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int len=n*m,tmp=0;
	for(int i=1;i<=len;i++){
		cin >> a[i].ex;
		a[i].id=i;
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++){
		if(a[i].id==1){
			tmp=i;
			break;
		}
	}
	if(tmp%m==0){
		int lie=tmp/m;
		if(lie%2==0)
			cout <<lie << " " << 1;
		else cout << lie << ' ' << n;
	}else{
		double lie=ceil((double)tmp/(double)m);
		ll lie1=(ll)lie;
		cout << lie << " ";
		if(lie1%2!=0){
			int hang=tmp%m;
			cout <<hang;
		}else{
			int hang=tmp%m;
			cout << m-hang+1;
		}
	}
	return 0;
}
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
