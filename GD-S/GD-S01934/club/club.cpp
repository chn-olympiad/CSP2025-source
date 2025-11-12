#include<bits/stdc++.h>
using namespace std;
struct cl{
	int x,y,z;
}a[100001];
int t,n,cnt0,cnt1,cnt2;
long long m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt0=cnt1=cnt2=m=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y && a[i].x>a[i].z){
				cnt0++;
				m+=a[i].x;
			}
			else if(a[i].y>a[i].x && a[i].y>a[i].z){
				cnt1++;
				m+=a[i].y;
			}
			else{
				cnt2++;
				m+=a[i].z;
			}
		}
		if(cnt0>n/2){
			sort(a+1,a+n+1,[](cl p,cl q){
				if(p.x>p.y && p.x>p.z){
					if(q.x>q.y && q.x>q.z) return min(p.x-p.y,p.x-p.z)<min(q.x-q.y,q.x-q.z);
					else return true;
				}
				else return false;
			});
			for(int i=1;i<=n && cnt0>n/2;i++){
				cnt0--;
				m-=a[i].x;
				if(a[i].y>a[i].z){
					cnt1++;
					m+=a[i].y;
				}
				else{
					cnt2++;
					m+=a[i].z;
				}
			}
		}
		else if(cnt1>n/2){
			sort(a+1,a+n+1,[](cl p,cl q){
				if(p.y>p.x && p.y>p.z){
					if(q.y>q.x && q.y>q.z) return min(p.y-p.x,p.y-p.z)<min(q.y-q.x,q.y-q.z);
					else return true;
				}
				else return false;
			});
			for(int i=1;i<=n && cnt1>n/2;i++){
				cnt1--;
				m-=a[i].y;
				if(a[i].x>a[i].z){
					cnt0++;
					m+=a[i].x;
				}
				else{
					cnt2++;
					m+=a[i].z;
				}
			}
		}
		else if(cnt2>n/2){
			sort(a+1,a+n+1,[](cl p,cl q){
				if(p.z>p.x && p.z>p.y){
					if(q.z>q.x && q.z>q.y) return min(p.z-p.x,p.z-p.y)<min(q.z-q.x,q.z-q.y);
					else return true;
				}
				else return false;
			});
			for(int i=1;i<=n && cnt2>n/2;i++){
				cnt2--;
				m-=a[i].z;
				if(a[i].x>a[i].y){
					cnt0++;
					m+=a[i].x;
				}
				else{
					cnt1++;
					m+=a[i].y;
				}
			}
		}
		cout<<m<<'\n';
	}
	return 0;
}
