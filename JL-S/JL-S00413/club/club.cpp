#include<bits/stdc++.h>
using namespace std;
struct f{
	int mx,cha1,cha2,mid,mn,m1,m2,m3;
}a[100010];
struct k{
	int num,seat;
}m[5];
bool c(k a,k b){
	return a.num<b.num;
}bool cmp(f a,f b){
	if(a.cha1!=b.cha1)return a.cha1>b.cha1;
	if(a.mx!=b.mx)return a.mx>b.mx;
	if(a.cha2!=b.cha2)return a.cha2>b.cha2;
	if(a.mid!=b.mid)return a.mid>b.mid;
	return a.mn>b.mn;
}int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int sum[5]={0,0,0,0,0},ans=0,n;
		cin>>n;int len=n/2;
		for(int i=1;i<=n;i++){
			cin>>m[1].num>>m[2].num>>m[3].num;
			m[1].seat=1,m[2].seat=2,m[3].seat=3;
			sort(m+1,m+4,c);
			a[i].mx=m[3].num,a[i].mid=m[2].num,a[i].mn=m[1].num;
			a[i].m1=m[3].seat,a[i].m2=m[2].seat,a[i].m3=m[1].seat;
			a[i].cha1=a[i].mx-a[i].mid;a[i].cha2=a[i].mid-a[i].mn;
		}sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(sum[a[i].m1]+1<=len){
				ans+=a[i].mx,sum[a[i].m1]++;
				continue;
			}if(sum[a[i].m2]+1<=len){
				ans+=a[i].mid,sum[a[i].m2]++;
				continue;
			}if(sum[a[i].m3]+1<=len){
				ans+=a[i].mn,sum[a[i].m3]++;
				continue;
			}
		}cout<<ans<<endl;
	}return 0;
}
