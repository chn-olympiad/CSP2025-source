#include<bits/stdc++.h>
using namespace std;
int t;
struct preson{
	int i;
	int a1,a2,a3;
	int best,mid,last;
	int ans = 0;
}a[100001];
int fenpei(int n,int s){
	int p1 = 0,p2 = 0,p3 = 0;
	for(int i = 1;i<=n;i++){
		if(a[i].best == 1){
			if(p1>s){
				if(a[i].mid == 2){
					if(p2>s){
						p3++;
						a[i].ans = a[i].a3;
						continue;
					}else{
						p2++;
						a[i].ans = a[i].a2;
						continue;
					}
				}
				if(a[i].mid == 3){
					if(p3>s){
						p2++;
						a[i].ans = a[i].a2;
						continue;
					}else{
						p3++;
						a[i].ans = a[i].a3;
						continue;
					}
				}
			}else{
				p1++;
				a[i].ans = a[i].a1;
				continue;
			}
		}
		
		if(a[i].best == 2){
			if(p2>s){
				if(a[i].mid == 1){
					if(p1>s){
						p3++;
						a[i].ans = a[i].a3;
						continue;
					}else{
						p1++;
						a[i].ans = a[i].a1;
						continue;
					}
				}
				if(a[i].mid == 3){
					if(p1>s){
						p2++;
						a[i].ans = a[i].a1;
						continue;
					}else{
						p3++;
						a[i].ans = a[i].a3;
						continue;
					}
				}
			}else{
				p2++;
				a[i].ans = a[i].a2;
				continue;
			}
		}
		
		if(a[i].best == 3){
			if(p3>s){
				if(a[i].mid == 2){
					if(p2>s){
						p1++;
						a[i].ans = a[i].a1;
						continue;
					}else{
						p2++;
						a[i].ans = a[i].a2;
						continue;
					}
				}
				if(a[i].mid == 1){
					if(p1>s){
						p2++;
						a[i].ans = a[i].a2;
						continue;
					}else{
						p1++;
						a[i].ans = a[i].a1;
						continue;
					}
				}
			}else{
				p3++;
				a[i].ans = a[i].a3;
				continue;
			}
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		ans = ans + a[i].ans;
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int s = n/2;
		for(int i = 1;i<=n;i++){
			a[i].i = i;
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			
			if(a[i].a1<=a[i].a2<=a[i].a3) a[i].best = 3;
			if(a[i].a1<=a[i].a3<=a[i].a2) a[i].best = 2;
			if(a[i].a2<=a[i].a1<=a[i].a3) a[i].best = 3;
			if(a[i].a2<=a[i].a3<=a[i].a1) a[i].best = 1;
			if(a[i].a3<=a[i].a1<=a[i].a2) a[i].best = 2;
			if(a[i].a3<=a[i].a2<=a[i].a1) a[i].best = 1;
			cout<<a[i].best<<" "<<endl;
			
			if(a[i].a1<=a[i].a2<=a[i].a3) a[i].mid = 2;
			if(a[i].a1<=a[i].a3<=a[i].a2) a[i].mid = 3;
			if(a[i].a2<=a[i].a1<=a[i].a3) a[i].mid = 1; 
			if(a[i].a2<=a[i].a3<=a[i].a1) a[i].mid = 3;
			if(a[i].a3<=a[i].a1<=a[i].a2) a[i].mid = 1;
			if(a[i].a3<=a[i].a2<=a[i].a1) a[i].mid = 2;
			cout<<a[i].mid<<" "<<endl;
			
			if(a[i].a1<=a[i].a2<=a[i].a3) a[i].last = 1;
			if(a[i].a1<=a[i].a3<=a[i].a2) a[i].last = 1;
			if(a[i].a2<=a[i].a1<=a[i].a3) a[i].last = 2;
			if(a[i].a2<=a[i].a3<=a[i].a1) a[i].last = 2;
			if(a[i].a3<=a[i].a1<=a[i].a2) a[i].last = 3;
			if(a[i].a3<=a[i].a2<=a[i].a1) a[i].last = 3;
			cout<<a[i].last<<" "<<endl;
		}
		int ans = fenpei(n,s);
		cout<<ans<<endl;
	}
	return 0;
}
