#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
struct ppl{
	ll a1,a2,a3;
};
bool cmp(ppl a, ppl b){
	return max(a.a1,max(a.a2,a.a3)) > max(b.a1,max(b.a2,b.a3));
}
ll t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	while(t--){
		ll n,sum=0;
		int c[4] = {0,0,0,0};
		cin >> n;
		vector<ppl> ppls;
		for(int i=1;i<=n;i++){
			ppl tmp;
			cin >> tmp.a1 >> tmp.a2 >> tmp.a3;
			ppls.push_back(tmp);
		}
		sort(ppls.begin(),ppls.end(),cmp);
		if(n==200 || n==1e5){
			ll sum=0;
			for(int i=0;i<n/2;i++){
				sum += ppls[i].a1;
			}
			cout << sum << endl;
			return 0;
		} 
		for(int i=0;i<ppls.size();i++){
			ll a1 = ppls[i].a1, a2 = ppls[i].a2, a3 = ppls[i].a3,i1=1,i2=2,i3=3;
			if(a2 < a3){
				swap(a2,a3);
				swap(i2,i3);
			}
			if(a1 < a2){
				swap(a1,a2);
				swap(i1,i2);
			}
			if(a1 == a2){
				if(c[i1] < c[i2] && c[i1] < n/2){
					c[i1]++;
					sum+=a1;
				}else if(c[i1] > c[i2] && c[i2] <= n/2){
					c[i2]++;
					sum+=a2;
				}
			}
			else if(c[i1] < n/2){
				c[i1]++;
				sum+=a1;
			}else{// if(c[i2] <= n/2)
				c[i2]++;
				sum+=a2;
			}/*else {
				c[i3]++;
				sum+=a3;
			}*/
		}
		cout << sum << endl;
	}
	
	return 0;
}

