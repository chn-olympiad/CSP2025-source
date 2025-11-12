#include<bits/stdc++.h>
using namespace std;

int t,n;
struct pter{
	int v1,i1,v2,i2,v3,i3,id;
};
struct qren{
	int id,val;
	bool operator <(const qren& x)const{
		return val>x.val;
	}
};
int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		long long ans=0;
		queue<pter>per;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;		
			int ma1=0,mid1=0,ma2=0,mid2=0,ma3=0,mid3=0;
			if(a1>a2){
				ma1=a1;
				mid1=1;
			}else{
				ma1=a2;
				mid1=2;
			}
			if(ma1<a3){
				ma1=a3;
				mid1=3;
			}
			if(mid1==1){
				if(a2>a3){
					ma2=a2;
					mid2=2;
					ma3=a3;
					mid3=3;
				}else{
					ma2=a3;
					mid2=3;
					ma3=a2;
					mid3=2;
				}
			}else if(mid1==2){
				if(a1>a3){
					ma2=a1;
					mid2=1;
					ma3=a3;
					mid3=3;
				}else{
					ma2=a3;
					mid2=3;
					ma3=a1;
					mid3=1;
				}
			}else{
				if(a1>a2){
					ma2=a1;
					mid2=1;
					ma3=a2;
					mid3=2;
				}else{
					ma2=a2;
					mid2=2;
					ma3=a1;
					mid3=1;
				}
			}
			per.push({ma1,mid1,ma2,mid2,ma3,mid3,i});	
		}
		int siz[5]={0,0,0,0,0};
		priority_queue<qren>q[4];
		while(per.size()){
			pter tmp=per.front();
			per.pop();
			int idx=tmp.id;
			int id1=tmp.i1,val1=tmp.v1;
			int id2=tmp.i2,val2=tmp.v2;
			int id3=tmp.i3,val3=tmp.v3;
			if(siz[id1]<(n/2)){
				q[id1].push({idx,val1});
				ans+=val1;
				siz[id1]++;
				continue;
			}else{
				qren im=q[id1].top();
				if(im.val<val1){
					q[id1].pop();
					q[id1].push({idx,val1});
					ans+=(val1-im.val);
					continue;
				}
			}
			if(siz[id2]<(n/2)){
				q[id2].push({idx,val2});
				ans+=val2;
				siz[id2]++;
				continue;
			}else{
				qren im=q[id2].top();
				if(im.val<val2){
					q[id2].pop();
					q[id2].push({idx,val2});
					ans+=(val2-im.val);
					continue;
				}
			}
			if(siz[id3]<(n/2)){
				q[id3].push({idx,val3});
				ans+=val3;
				siz[id3]++;
			}else{
				qren im=q[id3].top();
				if(im.val<val3){
					q[id3].pop();
					q[id3].push({idx,val3});
					ans+=(val3-im.val);
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

