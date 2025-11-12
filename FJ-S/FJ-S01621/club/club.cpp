#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int T,n;
int r[5];
struct node{
	int a_1,a_2,a_3;
	int am;
}a[N];

bool cmp(node a,node b){
	return a.am>b.am;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a_1>>a[i].a_2>>a[i].a_3;
			a[i].am=max(a[i].a_1,max(a[i].a_2,a[i].a_3));
			a[i].am=a[i].am*2-(a[i].a_1+a[i].a_2+a[i].a_3);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].a_1>a[i].a_2){
				if(a[i].a_1>a[i].a_3&&r[1]<n/2){
					r[1]++;
					ans+=a[i].a_1;
				}
				else if(a[i].a_2>a[i].a_3&&r[2]<n/2){
					r[2]++;
					ans+=a[i].a_2;
				}
				else {
					r[3]++;
					ans+=a[i].a_3;
				}
			}
			else if(a[i].a_2>a[i].a_3){
				if(r[2]<n/2){
					r[2]++;
					ans+=a[i].a_2;
				}
				else if(a[i].a_1>a[i].a_3&&r[1]<n/2){
					r[1]++;
					ans+=a[i].a_1;
				}
				else {
					r[3]++;
					ans+=a[i].a_3;
				}
			}
			else{
				if(r[3]<n/2){
					r[3]++;
					ans+=a[i].a_3;
				}
				else {
					r[2]++;
					ans+=a[i].a_2;
				}
			}
		}
		r[1]=0;
		r[2]=0;
		r[3]=0;
		cout<<ans<<"\n";
		
	}
	return 0;
}

