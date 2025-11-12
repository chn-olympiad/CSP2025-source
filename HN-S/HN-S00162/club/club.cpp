#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[300010];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		int ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>a[i+n]>>a[i+2*n];
		}
		sort(a+1,a+1+n);
		for(int i=n/2+1;i<=n;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
//ÎØÎØÎØ,±¬¸Î 
/*#include<bits/stdc++.h>
using namespace std;
int t;
int n;
bool usd[100010];
int cnt[10];
struct node{
	int a;
	int b;
	int c;
	int maxx=max(a,max(b,c));
	int minn=min(a,min(b,c));
	int mid;
	int usd;
	int used;
}a[100010];
struct node1{
	int id;
	int zhi;
	int club;
	bool operator<(const node1&e)const{
		return id>e.id;
	}
};
int main(){
	cin>>t;
	while(t--){
		int ans=0;
		priority_queue<node1> pq;
		priority_queue<node1> pq1;
		priority_queue<node1> pq2;
		priority_queue<node1> pq3;
		priority_queue<node1> pqyu;
		cin>>n;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(int i=1;i<=n;i++){
			usd[i]=0;
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a==a[i].maxx){
				a[i].mid=max(a[i].b,a[i].c);
			}
			if(a[i].b==a[i].maxx){
				a[i].mid=max(a[i].a,a[i].c);
			}
			if(a[i].c==a[i].maxx){
				a[i].mid=max(a[i].b,a[i].a);
			}
			pq.push({i,a[i].a,1});
			pq.push({i,a[i].b,2});
			pq.push({i,a[i].c,3});
		}
		while(!pq.empty()){
			node1 zj=pq.top();
			pq.pop();
			if(usd[zj.id]==true){
				pqyu.push(zj);
				continue;
			}
			if(cnt[zj.club]==n/2){
				pqyu.push(zj);
				continue;
			}
			if(zj.club==1){
				pq1.push(zj);
				ans+=zj.zhi;
				cnt[1]++;
				usd[zj.id]=zj.zhi;
				a[zj.id].used=1;
				a[zj.id].usd=zj.zhi;
			}else if(zj.club==2){
				pq2.push(zj);
				ans+=zj.zhi;
				cnt[2]++;
				a[zj.id].usd=zj.zhi;
				a[zj.id].used=2;
				a[zj.id].usd=zj.zhi;
			}else if(zj.club==3){
				pq3.push(zj);
				ans+=zj.zhi;
				cnt[3]++;
				a[zj.id].usd=zj.zhi;
				a[zj.id].used=3;
				a[zj.id].usd=zj.zhi;
			}
		}
		if(cnt[1]<n/2&&cnt[2]<n/2&&cnt[3]<n/2){
			cout<<ans<<endl;
			continue;
		}else{
			if(cnt[1]==n/2){
				while(cnt[1]>0&&!pqyu.empty()){
					node1 mid=pq1.top();
					node1 mid2=pqyu.top();
					if(mid.zhi==a[mid.id].maxx){
						if((cnt[a[mid2.id].used]<n/2)&&(mid.zhi<a[mid2.id].maxx-a[mid2.id].usd+a[mid.id].mid)){
							pq1.pop();
							pqyu.pop();
							ans-=mid.zhi;
							ans+=a[mid2.id].maxx-a[mid2.id].usd+a[mid.id].mid;
							if(a[mid2.id].used==1){
								pq1.push(mid2);
							}
							if(a[mid2.id].used==2){
								pq2.push(mid2);
								cnt[1]--;
								cnt[2]++;
							}
							if(a[mid2.id].used==3){
								pq3.push(mid2);
								cnt[1]--;
								cnt[3]++;
							}
						}else{
							pqyu.pop();
						}
					}
					
				}
			}
			if(cnt[2]==n/2){
				while(cnt[2]>0&&!pqyu.empty()){
					node1 mid=pq2.top();
					node1 mid2=pqyu.top();
					if(mid.zhi==a[mid.id].maxx){
						if((cnt[a[mid2.id].used]<n/2)&&(mid.zhi<a[mid2.id].maxx-a[mid2.id].usd+a[mid.id].mid)){
							pq2.pop();
							pqyu.pop();
							ans-=mid.zhi;
							ans+=a[mid2.id].maxx-a[mid2.id].usd+a[mid.id].mid;
							if(a[mid2.id].used==1){
								pq1.push(mid2);
								cnt[2]--;
								cnt[1]++;
							}
							if(a[mid2.id].used==2){
								pq2.push(mid2);
			
							}
							if(a[mid2.id].used==3){
								pq3.push(mid2);
								cnt[2]--;
								cnt[3]++;
							}
						}else{
							pqyu.pop();
						}
					}
					
				}
			}
			if(cnt[3]==n/2){
				while(cnt[3]>0&&!pqyu.empty()){
					node1 mid=pq3.top();
					node1 mid2=pqyu.top();
					if(mid.zhi==a[mid.id].maxx){
						if((cnt[a[mid2.id].used]<n/2)&&(mid.zhi<a[mid2.id].maxx-a[mid2.id].usd+a[mid.id].mid)){
							pq3.pop();
							pqyu.pop();
							ans-=mid.zhi;
							ans+=a[mid2.id].maxx-a[mid2.id].usd+a[mid.id].mid;
							if(a[mid2.id].used==1){
								pq1.push(mid2);
								cnt[3]--;
								cnt[1]++;
							}
							if(a[mid2.id].used==2){
								pq2.push(mid2);
								cnt[3]--;
								cnt[2]++;
							}
							if(a[mid2.id].used==3){
								pq3.push(mid2);
							}
						}else{
							pqyu.pop();
						}
					}
					
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}*/
