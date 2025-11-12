#include<bits/stdc++.h>

using namespace std;
long long n,k;
const int N=5e5+10;
long long a[N];
long long cnt[N];//Ç°×ºÒì»òºÍ 
bool rs[N];
struct test{
	int l;
	int r;
	int size;
}f[N];
bool cmp(test x,test y){
	return x.size<=y.size;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	cnt[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		cnt[i]=cnt[i-1]^a[i];
	}
	long long ans=0;
	int fw=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i!=1){
				long long num=cnt[j]^cnt[i-1];
				if(num==k){
					f[fw].l=i;
					f[fw].r=j;
					f[fw].size=j-i+1;
					fw++;
				}
				if(a[j]==k){
					f[fw].l=j;
					f[fw].r=j;
					f[fw].size=1;
					fw++;
				}
			}else{
				long long num=cnt[j];
				if(num==k){
					f[fw].l=i;
					f[fw].r=j;
					f[fw].size=j-i+1;
					fw++;
				}
			}
		}
	}
	sort(f+1,f+fw+1,cmp);
	int ll,rr;
	for(int i=1;i<=fw;i++){
		if(i==1){
			ll=f[i].l;
			rr=f[i].r;
			for(int j=ll;j<=rr;j++){
				rs[j]=1;
			}
			if(f[i].l==0&&f[i].r==0){
				continue;
			}
			ans++;
		}else{
			bool ccttbb=0;
				for(int j=f[i].l;j<=f[i].r;j++){
					if(rs[j]==1){
						ccttbb=1;
						for(int p=f[i].l;p<j;p++){
							rs[j]=0;
						}
						break;
					}
					rs[j]=1;
				}
				if(ccttbb==0){
					if(f[i].l==0&&f[i].r==0){
						continue;
					}
					ans++;
				}
		}
	}
	cout<<ans;
	return 0;
}

