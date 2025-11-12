#include<bits/stdc++.h>
using namespace std;
int a[500005][50],kk[50];//a¼ÇÂ¼Ç°×ººÍ 
int d[500005][25];
struct mm{
	int l,r;
}ans[500005];
bool cmp(mm x,mm y){
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;k>0;i++){
		kk[i]=k%2;
		k/=2;
	}
	int t;
	for(int i=1;i<=n;i++){
		cin>>t;
		for(int j=1;t>0;j++){
			d[i][j]=t%2;
			t/=2;
		}
		for(int j=1;j<=50;j++){
			if(d[i][j]!=a[i-1][j])
			a[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int f=0;
			for(int p=1;p<=50&&f==0;p++){
				if(kk[p]==0&&a[j][p]!=a[i-1][p])
				f=1;
				if(kk[p]==1&&a[j][p]==a[i-1][p])
				f=1;
			}
			if(f==0){
			cnt++;
			ans[cnt].l=i;
			ans[cnt].r=j;	
			}
		}
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<ans[i].l<<" "<<ans[i].r<<endl;
//	}
	sort(ans+1,ans+cnt+1,cmp);
	int anss=1,x=ans[1].l,y=ans[1].r;
	for(int i=2;i<=cnt;i++){
		if(ans[i].l>y){
			anss++;
			x=ans[i].l;
			y=ans[i].r;
		}else if(ans[i].r<y){
			y=ans[i].r;
		}
	}
	cout<<anss;
	return 0;
} 
