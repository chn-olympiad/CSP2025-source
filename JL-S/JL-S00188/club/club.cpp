#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct stu{
	int x,y,z;
}a[N];
stu b[3][N];
int cnt[5];
int maxi(stu i){
	int m=max(max(i.x,i.y),i.z);
	if(i.x==m)return 0;
	if(i.y==m)return 1;
	return 2;
}
int calc(stu i){
	int m1=max(max(i.x,i.y),i.z);
	int m2=min(min(i.x,i.y),i.z);
	if(i.x!=m1&&i.x!=m2)return i.x;
	if(i.y!=m1&&i.y!=m2)return i.y;
	return i.z;
}
bool cmp1(stu i,stu j){return i.x-calc(i)>j.x-calc(j);}
bool cmp2(stu i,stu j){return i.y-calc(i)>j.y-calc(j);}
bool cmp3(stu i,stu j){return i.z-calc(i)>j.z-calc(j);}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,res=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=0;i<3;i++)cnt[i]=0;
		for(int i=0;i<n;i++){
			int k=maxi(a[i]);
			b[k][cnt[k]]=a[i];
			cnt[k]++;
		}
		for(int i=0;i<3;i++){
			if(cnt[i]>n/2){
				if(i==0){
					sort(b[i],b[i]+cnt[i],cmp1);
					for(int j=0;j<n/2;j++)res+=b[i][j].x;
				}
				if(i==1){
					sort(b[i],b[i]+cnt[i],cmp2);
					for(int j=0;j<n/2;j++)res+=b[i][j].y;
				}
				if(i==2){
					sort(b[i],b[i]+cnt[i],cmp3);
					for(int j=0;j<n/2;j++)res+=b[i][j].z;
				}
				for(int j=n/2;j<cnt[i];j++)res+=calc(b[i][j]);
			}
			else{
				if(i==0)for(int j=0;j<cnt[i];j++)res+=b[i][j].x;
				if(i==1)for(int j=0;j<cnt[i];j++)res+=b[i][j].y;
				if(i==2)for(int j=0;j<cnt[i];j++)res+=b[i][j].z;
				
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
