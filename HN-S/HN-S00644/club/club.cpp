#include<bits/stdc++.h>
using namespace std;
struct pp{
	int aa;
	int bb;
};
//a好感 b编号 
struct node{
	pp a[4];
};
node person[100005];
struct node1{
	int aa;
	int bb;
	int cc;
};
bool cmp1(pp a,pp b){
	return a.aa>b.aa;
}
bool cmp2(node1 x,node1 y){
	return x.aa<y.aa;
}
int sum[4];
node1 changen[4][200005];//从i换到的代价 
int lch[4];
bool b[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long ans=0;
		lch[1]=0;
		lch[2]=0;
		lch[3]=0;
		sum[1]=0;
		sum[2]=0;
		sum[3]=0;
		int n;
		cin>>n;
		int maxn;
		if(n%2==0){
			maxn=n/2;
		}
		else{
			maxn=(n-1)/2;
		}
		for(int i=1;i<=n;i++){
			b[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>person[i].a[1].aa>>person[i].a[2].aa>>person[i].a[3].aa;
			person[i].a[1].bb=1;
			person[i].a[2].bb=2;
			person[i].a[3].bb=3;
			sort(person[i].a+1,person[i].a+1+3,cmp1);
			ans=ans+person[i].a[1].aa;
			sum[person[i].a[1].bb]++;
			
			lch[person[i].a[1].bb]++;
			changen[person[i].a[1].bb][lch[person[i].a[1].bb]].aa=person[i].a[1].aa-person[i].a[2].aa;
			changen[person[i].a[1].bb][lch[person[i].a[1].bb]].bb=2;
			changen[person[i].a[1].bb][lch[person[i].a[1].bb]].cc=i;
			lch[person[i].a[1].bb]++;
			changen[person[i].a[1].bb][lch[person[i].a[1].bb]].aa=person[i].a[1].aa-person[i].a[3].aa;
			changen[person[i].a[1].bb][lch[person[i].a[1].bb]].bb=3;
			changen[person[i].a[1].bb][lch[person[i].a[1].bb]].cc=i;
			
		}
		int dw=0;
		if(sum[1]>maxn){
			dw=1;
		}
		if(sum[2]>maxn){
			dw=2;
		}
		if(sum[3]>maxn){
			dw=3;
		}
		if(dw==0){
			cout<<ans<<endl;
			continue;
		}
		sort(changen[dw]+1,changen[dw]+1+lch[dw],cmp2);
		int cnt=0;
		while(1){
			cnt++;
			if(sum[dw]<=maxn){
				break;
			}
			if(b[changen[dw][cnt].cc]==1){
				continue;
			}
			if(sum[changen[dw][cnt].bb]>=maxn){
				continue;
			}
			ans-=changen[dw][cnt].aa;
			sum[dw]--;
			sum[changen[dw][cnt].bb]++;
			b[changen[dw][cnt].cc]=1;
		}
		cout<<ans<<endl;
	}
	return 0;
} 

