#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define int long long
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int ans=0,n;
		cin>>n;
		priority_queue<int> qa,qb,qc;
		bool isa=0,isb=0,isc=0;
		for(int i=0;i<n;i++){
			int a,b,c;
			cin >> a >> b >> c;
			if(a>=b && a>=c){
				ans+=a;
				if(!(isc||isb))qa.push(-(b>c?a-b:a-c));
				if(qa.size()>n/2){
					isa=1;
					ans+=qa.top();
					qa.pop();
				}
			}else if(b>=a && b>=c){
				ans+=b;
				if(!(isa||isc))qb.push(-(a>c?b-a:b-c));
				if(qb.size()>n/2){
					isb=1;
					ans+=qb.top();
					qb.pop();
				}
			}else if(c>=a && c>=b){
				ans+=c;
				if(!(isa||isb))qc.push(-(a>b?c-a:c-b));
				if(qc.size()>n/2){
					isc=1;
					ans+=qc.top();
					qc.pop();
				}
			}
			
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
