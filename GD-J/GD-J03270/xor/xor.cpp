#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<int>v[4*N];
struct stu{
	int l,r;
}t[N];
bool cmp(const stu&x,const stu&y){
	return x.r<y.r;
}
int n,k,w,l,r,mid,tmp,no,ans,num,nr,last,a[N],b[N],c[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	v[0].push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];//前缀异或和 
		v[b[i]].push_back(i);
	}
	for(int i=n;i;i--){
		c[i]=c[i+1]^a[i];//后缀异或和 
	}
	w=b[n]^k;
	for(int i=n+1;i;i--){
		no=w^c[i];
		l=0,r=v[no].size()-1,tmp=-1e9;
		while(l<=r){
			mid=(l+r)/2;
			if(v[no][mid]<i-1){
				l=mid+1;
				tmp=mid;
			}else r=mid-1;
		}
		if(tmp>=0){
			t[++num].l=v[no][tmp]+1;
			t[num].r=i-1;
		}
	}
	sort(t+1,t+num+1,cmp);
	for(int i=0;i<=num;){
		for(int j=i+1;j<=num;j++){
			if(t[j].l>t[i].r){
				i=j;
				break;
			}
		}
		if(last==i)break;
		ans++;
		last=i;
	}
	cout<<ans<<endl;
	return 0;
} //#Shang4Shan3Ruo6Shui4
/*
tmp^a[i]^b[j]=k
tmp^k=a[i]^b[j]
*/
