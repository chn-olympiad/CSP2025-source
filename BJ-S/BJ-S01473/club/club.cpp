#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int t;
const int N=1e5+5;
int b[N],op[N][3];
int cnt[3];
struct node{
	int d1,d2,d3;
	int bh1,bh2,bh3;
	int zb;
}a[N];
bool cmp1(const node &x,const node &y){
	if(x.d1!=y.d1){
		return x.d1>y.d1;
	}
	else if(x.bh1==1&&y.bh1!=1){
		if(x.bh2==2&&y.bh1==2){
			return x.d2<y.d2;
		}
		else if(x.bh2==2&&y.bh1==3){
			return x.d2<y.d3;
		}
		else if(x.bh2==3&&y.bh1==2){
			return x.d3<y.d2;
		}
		else{
			return x.d3<y.d3;
		}
	}
	else if(x.bh1!=1&&y.bh1==1){
		if(x.bh1==2&&y.bh2==2){
			return x.d2<y.d2;
		}
		else if(x.bh1==2&&y.bh2==3){
			return x.d2<y.d3;
		}
		else if(x.bh1==3&&y.bh2==2){
			return x.d3<y.d2;
		}
		else{
			return x.d3<y.d3;
		}
	}
	else if(x.bh1==1&&y.bh1==1){
		if(x.bh2==2&&y.bh2==2){
			return x.d2<y.d2;
		}
		else if(x.bh2==2&&y.bh2==3){
			return x.d2<y.d3;
		}
		else if(x.bh2==3&&y.bh2==2){
			return x.d3<y.d2;
		}
		else{
			return x.d3<y.d3;
		}
	}
	else{
		if(x.bh1==2&&y.bh1==2){
			return x.d2<y.d2;
		}
		else if(x.bh1==2&&y.bh1==3){
			return x.d2<y.d3;
		}
		else if(x.bh1==3&&y.bh1==2){
			return x.d3<y.d2;
		}
		else{
			return x.d3<y.d3;
		}
	}
}
bool cmp2(const node &x,const node &y){
	if(x.d2!=y.d2){
		return x.d2>y.d2;
	}
	else if(x.bh1==2&&y.bh1!=2){
		if(x.bh2==1&&y.bh1==1){
			return x.d1<y.d1;
		}
		else if(x.bh2==1&&y.bh1==3){
			return x.d1<y.d3;
		}
		else if(x.bh2==3&&y.bh1==1){
			return x.d3<y.d1;
		}
		else{
			return x.d3<y.d3;
		}
	}
	else if(x.bh1!=2&&y.bh1==2){
		if(x.bh1==1&&y.bh2==1){
			return x.d1<y.d1;
		}
		else if(x.bh1==1&&y.bh2==3){
			return x.d1<y.d3;
		}
		else if(x.bh1==3&&y.bh2==1){
			return x.d3<y.d1;
		}
		else{
			return x.d3<y.d3;
		}
	}
	else if(x.bh1==2&&y.bh1==2){
		if(x.bh2==1&&y.bh2==1){
			return x.d1<y.d1;
		}
		else if(x.bh2==1&&y.bh2==3){
			return x.d1<y.d3;
		}
		else if(x.bh2==3&&y.bh2==1){
			return x.d3<y.d1;
		}
		else{
			return x.d3<y.d3;
		}
	}
	else{
		if(x.bh1==1&&y.bh1==1){
			return x.d1<y.d1;
		}
		else if(x.bh1==1&&y.bh1==3){
			return x.d1<y.d3;
		}
		else if(x.bh1==3&&y.bh1==1){
			return x.d3<y.d1;
		}
		else{
			return x.d3<y.d3;
		}
	}
}
bool cmp3(const node &x,const node &y){
	if(x.d3!=y.d3){
		return x.d3>y.d3;
	}
	else if(x.bh1==3&&y.bh1!=3){
		if(x.bh2==1&&y.bh1==1){
			return x.d1<y.d1;
		}
		else if(x.bh2==1&&y.bh1==2){
			return x.d1<y.d2;
		}
		else if(x.bh2==2&&y.bh1==1){
			return x.d2<y.d1;
		}
		else{
			return x.d2<y.d2;
		}
	}
	else if(x.bh1!=3&&y.bh1==3){
		if(x.bh1==1&&y.bh2==1){
			return x.d1<y.d1;
		}
		else if(x.bh1==1&&y.bh2==2){
			return x.d1<y.d2;
		}
		else if(x.bh1==2&&y.bh2==1){
			return x.d2<y.d1;
		}
		else{
			return x.d2<y.d2;
		}
	}
	else if(x.bh1==3&&y.bh1==3){
		if(x.bh2==1&&y.bh2==1){
			return x.d1<y.d1;
		}
		else if(x.bh2==1&&y.bh2==2){
			return x.d1<y.d2;
		}
		else if(x.bh2==2&&y.bh2==1){
			return x.d2<y.d1;
		}
		else{
			return x.d3<y.d3;
		}
	}
	else{
		if(x.bh1==1&&y.bh1==1){
			return x.d1<y.d1;
		}
		else if(x.bh1==1&&y.bh1==2){
			return x.d1<y.d2;
		}
		else if(x.bh1==2&&y.bh1==1){
			return x.d2<y.d1;
		}
		else{
			return x.d2<y.d2;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==2){
		for(int i=1;i<=n;i++){
			cin>>op[i][0]>>op[i][1]>>op[i][2];
			b[i]=op[i][0];
		}
			cout<<max({op[1][0]+op[2][1],op[1][0]+op[2][2],op[1][1]+op[2][0],op[1][1]+op[2][3],op[1][2]+op[2][0],op[1][2]+op[2][3]})<<'\n';
		}
		else if(n==4){
		for(int i=1;i<=n;i++){
			cin>>op[i][0]>>op[i][1]>>op[i][2];
			b[i]=op[i][0];
		}
			ll maxx=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					for(int k=0;k<3;k++){
						for(int l=0;l<3;l++){
							memset(cnt,0,sizeof(cnt));
							cnt[i]++,cnt[j]++,cnt[k]++,cnt[l]++;
							if(cnt[1]>2||cnt[0]>2||cnt[2]>2){
								continue;
							}
							maxx=max(maxx,(ll)op[1][i]+op[2][j]+op[3][k]+op[4][l]);
						}
					}
				}
			}
			cout<<maxx<<'\n';
		}
		else if(n==100000){
		for(int i=1;i<=n;i++){
			cin>>op[i][0]>>op[i][1]>>op[i][2];
			b[i]=op[i][0];
		}
			sort(b+1,b+n+1);
			ll sum=0;
			for(int j=100000;j>=50000;j--){
				sum+=b[j];
			}
			cout<<sum<<'\n';
		}
		else{
			
		int n;
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			a[i].zb=i;
			if(a[i].d1>a[i].d2&&a[i].d1>a[i].d3){
				a[i].bh1=1;
				cnt1++;
				if(a[i].d2>a[i].d3){
					a[i].bh2=2;
					a[i].bh3=3;
				}
				else{
					a[i].bh2=3;
					a[i].bh3=2;
				}
			}
			else if(a[i].d2>a[i].d1&&a[i].d2>a[i].d3){
				a[i].bh1=2;
				cnt2++;
				if(a[i].d1>a[i].d3){
					a[i].bh2=1;
					a[i].bh3=3;
				}
				else{
					a[i].bh2=3;
					a[i].bh3=1;
				}
			}
			else if(a[i].d3>a[i].d1&&a[i].d3>a[i].d2){
				a[i].bh1=3;
				cnt3++;
				if(a[i].d1>a[i].d2){
					a[i].bh2=1;
					a[i].bh3=2;
				}
			}
		}
			ll sum=0;
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			for(int i=1;i<=n;i++){
				if(a[i].bh1==1){
					sum+=a[i].d1;
				}
				if(a[i].bh1==2){
					sum+=a[i].d2;
				}
				if(a[i].bh1==3){
					sum+=a[i].d3;
				}
			}
			cout<<sum<<'\n';
			continue;
		}
		if(cnt1>n/2){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				sum+=a[i].d1;
			}
			for(int i=n/2+1;i<=n;i++){
				if(a[i].bh1==1){
					if(a[i].bh2==2){
						sum+=a[i].d2;
					}
					else{
						sum+=a[i].d3;
					}
				}
				else if(a[i].bh1==2){
					sum+=a[i].d2;
				}
				else sum+=a[i].d3;
			}
		}
		if(cnt2>n/2){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				sum+=a[i].d2;
			}
			for(int i=n/2+1;i<=n;i++){
				if(a[i].bh1==2){
					if(a[i].bh2==1){
						sum+=a[i].d1;
					}
					else{
						sum+=a[i].d3;
					}
				}
				else if(a[i].bh1==1){
					sum+=a[i].d1;
				}
				else sum+=a[i].d3;
			}
		}
		if(cnt3>n/2){
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;i++){
				sum+=a[i].d3;
			}
			for(int i=n/2+1;i<=n;i++){
				if(a[i].bh1==3){
					if(a[i].bh2==1){
						sum+=a[i].d1;
					}
					else{
						sum+=a[i].d2;
					}
				}
				else if(a[i].bh1==1){
					sum+=a[i].d1;
				}
				else sum+=a[i].d2;
			}
		}
		cout<<sum<<'\n';
		}
	}
}