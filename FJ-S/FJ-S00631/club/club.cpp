#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct club {
	int mya;
	int myb;
	int myc;
} stu[N];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		int a=0,b=0,c=0;
		long long ans=0;
		cin>>n;
		int k=n/2;
		for(int i=1; i<=n; i++) {
			cin>>stu[i].mya>>stu[i].myb>>stu[i].myc;
		}
		for(int i=1; i<=n; i++) {
			if(stu[i].mya>=stu[i].myb&&stu[i].mya>=stu[i].myc) {
				if(a>=k) {
					if(stu[i].mya>stu[i-1].mya) {
						ans=ans-stu[i-1].mya+stu[i].mya;
					}
				}
				else{
				ans=ans+stu[i].mya;
				a++;
			}
			} else if(stu[i].myb>=stu[i].mya&&stu[i].myb>=stu[i].myc) {
				if(b>=k) {
					if(stu[i].myb>stu[i-1].myb) {
						ans=ans-stu[i-1].myb+stu[i].myb;
					}
				}
				else{
				ans=ans+stu[i].myb;
				b++;
			}
			}
			 else if(stu[i].myc>=stu[i].mya&&stu[i].myc>=stu[i].myb) {
				if(c>=k) {
					if(stu[i].myc>stu[i-1].myc) {
						ans=ans-stu[i-1].myc+stu[i].myc;
					}
				}
				else{
				ans=ans+stu[i].myc;
				c++;
			}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
