#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int cnt1,cnt2,cnt3;
int max1[N],max2[N],max3[N];
int n,k,shu;
struct node{
	int a1,a2,a3,a,b,cha;
}cha1[N];

bool cmp(node x,node y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		int sum=0,k=0;
		cnt1=cnt2=cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cha1[i].a1>>cha1[i].a2>>cha1[i].a3;
			max1[i]=max(cha1[i].a1,max(cha1[i].a2,cha1[i].a3));
			max3[i]=min(cha1[i].a1,min(cha1[i].a2,cha1[i].a3));
			if(cha1[i].a1!=max1[i]&&cha1[i].a1!=max3[i]) max2[i]=cha1[i].a1;
			else if(cha1[i].a2!=max1[i]&&cha1[i].a2!=max3[i]) max2[i]=cha1[i].a2;
			else max2[i]=cha1[i].a3;
			if((cha1[i].a1==cha1[i].a2)||(cha1[i].a1==cha1[i].a3)) max2[i]=cha1[i].a1;
			else if(cha1[i].a2==cha1[i].a3) max2[i]=cha1[i].a2;
			cha1[i].cha=max1[i]-max2[i];
			cha1[i].a=max1[i];
			cha1[i].b=max2[i];
		}
		sort(cha1+1,cha1+n+1,cmp);
		for(int i=1;i<=n;i++){
			sum+=cha1[i].a;
			if(cha1[i].a1==cha1[i].a){
				cnt1++;
			}else if(cha1[i].a2==cha1[i].a){
				cnt2++;
			}else{
				cnt3++;
			}
			cha1[i].a1=cha1[i].a2=cha1[i].a3=0;
			if(cnt1==n/2){
				k=1;
				shu=i;
				break;
			}else if(cnt2==n/2){
				k=2;
				shu=i;
				break;
			}else if(cnt3==n/2){
				k=3;
				shu=i;
				break;
			}
		}
		for(int i=shu;i<=n;i++){
			if(k==1){
				sum+=max(cha1[i].a2,cha1[i].a3);
			}else if(k==2){
				sum+=max(cha1[i].a1,cha1[i].a3);
			}else if(k==3){
				sum+=max(cha1[i].a1,cha1[i].a2);
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
