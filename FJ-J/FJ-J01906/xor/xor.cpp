#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
ll n,a[N],k,ans=0;
queue<ll> le,ri; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll l=1,r=n,h=1,num=0,xx=0,b=1,c,d;
	le.push(l),ri.push(r);
	while(!le.empty()){
		xx++;
		l=le.front(),r=ri.front();
		ll p=l;
		bool o=false;
		for(int i=l;i<=r-h+1;i++){
			int q=a[i];
//			if(a[i]==0&&k!=0) continue;
			for(int j=l+1;j<l+h;j++){
				q^=a[j];
			}
			if(q==k){
				ans++;
				if(i-p>h){
				cout<<i<<' '<<i+h-1<<endl;
				cout<<p<<' '<<i-1<<endl;
				le.push(p);
				ri.push(i-1);
				num++;
				}
				p=i+1;	
				o=true;
//				cout<<ans;
			}
		}
		if(r-p+1>h&&o) {
			le.push(p);
			ri.push(r);
		}
		if(r-l+1>h&&!o){
			num++;
			le.push(le.front());
			ri.push(ri.front());
			le.pop();
			ri.pop();
		} 
		if(o||(r-l+1)<=h){
			le.pop();ri.pop() ;
		}
//		cout<<num<<' ';
//		cout<<le.back()<<' '<<ri.back()<<' ';
//		cout<<l<<' '<<r<<' '<<h<<' '<<num<<' '<<b<<' '<<o<<endl;
		if(b==xx){
			h++;
//			cout<<num<<' ';
			b=num;
			num=0;
			xx=0;
//		cout<<1;
		}
		if(b==0) break;
	}
	cout<<ans;
//	if(system("fc xor4.in xor4.out")){
//		cout<<"WR";
//	}
//	else cout<<"AC";
	return 0;
}
/*4 3
2 1 0 3
4 0
2 1 0 3*/

