#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
hello there is Luogu uid:1340395 @tc291311
chuyi ruoju 
upd 9:05
T1's time is O(nlogn) i can't think any solution,maybe get min76,max100
but i tkink is da gai lv get 100,because sort should be nlogn,has O(n) solution?
T2 is a water problem,AC
I'll AK?
now max=100+100=200
now min=76+100=176
T3 is very hark for me,baoli dou xie bu chu lai
upd 9:33
T3's baoli is been done!!!!
now max=100+100+40+0=240
now min=76+100+40+0=216 
upd 9:44
T4??

upd 10:14
T4 may get 24 points!
now max=100+100+40+24=264
now min=76+100+40+24=240
let me go back ot T3 and think about it.

upd 10:24
T3 de B i can get all,so score+=5
now max=100+100+45+24=269
now min=76+100+45+24=245

upd 10:28
no,T3 de baoli why cannot tongguo yangli 5?
now min=76+100+20+24=225

upd 11:10
mao si baoli de da an ke yi bei wo de qi ta xie fa hack diao
now min=76+100+25+24=230

now score:230~269

upd 11:18

ei~T4 can get also 12 too!
now score:242~281
*/
/*
5
1 2 3 4 5
*/
const int N=5005;
ll n;
ll a[N];
const int mod=998244353;
ll l[N];
ll ans;
bool check(int m){
	ll sum=0,maxx=0;
	for(int i=1;i<=m;i++){
		sum+=l[i];
		maxx=max(maxx,l[i]);
	}
	return (sum>(2*maxx));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n==3){
		for(int i=1;i<=n;i++){
			l[i]=a[i];
		}
		if(check(n)){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		memset(l,0,sizeof(l));
		for(int j=1;j<=i;j++){
			l[j]=a[j];
		}
		if(check(i)){
			ans++;
			ans%=mod;
//			cout<<i<<" ";
		}
	}
	cout<<ans%mod;
	return 0;
}
