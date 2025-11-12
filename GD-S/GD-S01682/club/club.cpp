#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n == 2){
			int a1,a2,a3,b1,b2,b3;
			cin>>a1>>a2>>a3>>b1>>b2>>b3;
			if(a1 == a2 && a2 == a3 && b1 == b2 && b2 == b3) cout<<a1 + b1<<endl;
			else if(a1 == a2 && a2 == a3 && b1 == b2) cout<<a1 + max(b1,b3)<<endl;
			else if(a1 == a2 && a2 == a3 && b1 == b3) cout<<a1 + max(b1,b2)<<endl;
			else if(a1 == a2 && a2 == a3 && b2 == b3) cout<<a1 + max(b1,b2)<<endl;
			else if(a1 == a2 && b1 == b2 && b2 == b3) cout<<max(a1,a3) + b1<<endl;
			else if(a1 == a3 && b1 == b2 && b2 == b3) cout<<max(a1,a2) + b1<<endl;
			else if(a2 == a3 && b1 == b2 && b2 == b3) cout<<max(a1,a2) + b1<<endl;
			else if(a1 + b2 > a1 + b3 && a1 + b2 > a2 + b1 && a1 + b2 > a2 + b3 && a1 + b2 > a3 + b1 && a1 + b2 > a3 + b2) cout<<a1 + b2<<endl;
			else if(a1 + b3 > a1 + b2 && a1 + b3 > a2 + b1 && a1 + b3 > a2 + b3 && a1 + b3 > a3 + b1 && a1 + b3 > a3 + b2) cout<<a1 + b3<<endl;
			else if(a2 + b1 > a1 + b2 && a2 + b1 > a1 + b3 && a2 + b1 > a2 + b3 && a2 + b1 > a3 + b1 && a2 + b1 > a3 + b2) cout<<a2 + b1<<endl;
			else if(a2 + b3 > a1 + b2 && a2 + b3 > a1 + b3 && a2 + b3 > a2 + b1 && a2 + b3 > a3 + b1 && a2 + b3 > a3 + b2) cout<<a2 + b3<<endl;
			else if(a3 + b1 > a1 + b2 && a3 + b1 > a1 + b3 && a3 + b1 > a2 + b1 && a3 + b1 > a2 + b3 && a3 + b1 > a3 + b2) cout<<a3 + b1<<endl;
			else if(a3 + b2 > a1 + b2 && a3 + b2 > a1 + b3 && a3 + b2 > a2 + b1 && a3 + b2 > a2 + b3 && a3 + b2 > a3 + b1) cout<<a3 + b2<<endl;
		}else{
			long long cnt = 0;
			for(int i = 0;i < n;i++){
				int a1,a2,a3;
				cin>>a1>>a2>>a3;
				cnt += max(a1,max(a2,a3)); 
			}
			cout<<cnt;
		}
	}
	return 0;
}
