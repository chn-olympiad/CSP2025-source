#include <bits/stdc++.h>
using namespace std;
struct pv{
	int dptmt,count;
};
struct psn{
	int a1,a2,a3,id;
	pv r1,r2,r3;
	bool isadded=0;
	void px(){
		if(a1>=a2&& a2>=a3){
			//cout<<1;
			r1.count=a1;r1.dptmt=1;
			r2.count=a2;r2.dptmt=2;
			r3.count=a3;r2.dptmt=3;
		}
		else if(a1>=a3&& a3>=a2){
			//cout<<2;
			r1.count=a1;r1.dptmt=1;
			r2.count=a3;r2.dptmt=3;
			r3.count=a2;r3.dptmt=2;
		}
		else if(a2>=a1&&a1>=a3){
			//cout<<3;
			r1.count=a2;r1.dptmt=2;
			r2.count=a1;r2.dptmt=1;
			r3.count=a3;r3.dptmt=3;
		}
		else if(a2>=a3&&a3>=a1){
			//cout<<4;
			r1.count=a2;r1.dptmt=2;
			r2.count=a1;r2.dptmt=1;
			r3.count=a3;r3.dptmt=3;
		}
		else if(a3>=a1&&a1>=a2){
			//cout<<5;
			r1.count=a3;r1.dptmt=3;
			r2.count=a1;r2.dptmt=1;
			r3.count=a2;r3.dptmt=2;
		}
		else if(a3>=a2&&a2>=a1){
			//cout<<6;
			r1.count=a3;r1.dptmt=3;
			r2.count=a2;r2.dptmt=2;
			r3.count=a1;r3.dptmt=1;
		}
	}
};
bool cmp1(psn a,psn b){
	return a.a1>b.a1;
}
bool cmp2(psn a,psn b){
	return a.a2>b.a2;
}
bool cmp3(psn a,psn b){
	return a.a3>b.a3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<psn> v(n+10);
		for(int i=1;i<=n;i++){
			cin>>v[i].a1>>v[i].a2>>v[i].a3;
			v[i].id=i;
			v[i].px();
		}
		vector<psn> v1=v;vector<psn> v2=v;vector<psn>v3=v;
		sort(v1.begin()+1,v1.begin()+1+n,cmp1);sort(v2.begin()+1,v2.begin()+1+n,cmp2);sort(v3.begin()+1,v3.begin()+1+n,cmp3);
		int c[4]={0,0,0,0};
		int ans=0;
		int s1=1,s2=1;
		for(int i=1;i<=n;i++){
			v[v1[i].id].isadded=1;
			ans+=v1[i].a1;
			c[1]++;
		}
		for(int i=1;i<=n;i++){
			if(c[2]>=n/2) break;
			if(v[v2[i].id].isadded){
				if(v2[i].a2>v2[i].a1){
					//cout<<111<<endl;
					ans-=v2[i].a1;
					ans+=v2[i].a2;
					c[2]++;
					//cout<<v1[n/2+1].a1;
				}
				continue;
			}
			v[v2[i].id].isadded=1;
			ans+=v2[i].a2;
			c[2]++;
		}
		for(int i=1;i<=n;i++){
			if(c[3]>=n/2) break;
			if(v[v3[i].id].isadded){
				if(v3[i].a3>v3[i].a1 && v3[i].a1>v3[i].a2){
					ans-=v3[i].a1;
					ans+=v3[i].a3;
					c[1]--;
					c[3]++;
				}
				else if(v3[i].a3>v3[i].a2 && v3[i].a2>v3[i].a1){
					ans-=v3[i].a2;
					ans+=v3[i].a3;
					c[2]--;
					c[3]++;
				}
				continue;
			}
			v[v3[i].id].isadded=1;
				ans+=v3[i].a3;
				c[3]++;
		}
		for(int i=1;i<=n;i++){
			if(!v[i].isadded){
				if(c[v[i].r1.dptmt]<n/2){
					c[v[i].r1.dptmt]++;
					ans+=v[i].r1.count;
				}
				else if(c[v[i].r2.dptmt]<n/2){
					c[v[i].r2.dptmt]++;
					ans+=v[i].r2.count;
				}
				else{
					c[v[i].r3.dptmt]++;
					ans+=v[i].r3.count;
				}			
			}
		}
		cout<<ans;
	}
	return 0;
}
