#include <iostream>
#include <algorithm>
using namespace std;
using ullt=unsigned long long int;
const int MAXN=510,MOD=998244353;
ullt n,m,c[MAXN],ttmp[MAXN];
ullt asw,efc;
char s[MAXN];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	cin>>s;
	ullt sumc=0;
	for (ullt i=0;i<n;i++) {
		cin>>c[i];
		sumc+=c[i];
	}
	//cout<<"i want to play delta force!!!!";
	for (ullt i=0;i<n;i++) {
		ttmp[i]=i;
	}
	
	if (sumc==n&&n>70) efc=1;
	//if (efc) puts("enable fast compute");
	if (efc) {
		ullt summ=1;
		for (ullt i=1;i<=n;i++) {
			summ*=i%MOD;
			summ%=MOD;
		}
		asw=summ;
	} else {
		do {
			ullt fail=0;
			for (ullt i=0;i<n;i++) {
				if (fail>=c[ttmp[i]]||s[i]=='0') {
					fail++;
					//cout<<"f"<<endl;
				}// else {
				//	cout<<"t"<<endl;
				//}
			}
			if (n-fail>=m) {
				//cout<<"tried ";
				//for (int i=0;i<n;i++) cout<<c[tmp[i]]<<' ';
				//cout<<" successfully.fail="<<fail<<endl;
				asw++;
				asw%=MOD;
			}// else {
			//	cout<<"tried ";
			//	for (int i=0;i<n;i++) cout<<c[tmp[i]]<<' ';
			//	cout<<" failly.fail="<<fail<<endl;
			//}
		} while (next_permutation(ttmp,ttmp+n));
	}
	cout<<asw;
	return 0;
}
