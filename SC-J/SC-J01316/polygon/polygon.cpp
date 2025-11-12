#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+15;
int a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int maxn=max(a[0],max(a[1],a[2]));
		int sm=a[0]+a[1]+a[2];
		if(sm>2*maxn){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(n == 10){
		int lsm=0;
		for(int  i = 0; i < n; i++){
			lsm+=a[i];
		}
		int ans=0,ans3=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					int sm=a[i]+a[j]+a[k],maxn=max(a[i],max(a[j],a[k]));
					if(sm>2*maxn) ans3++;
				}
			}
		}
		ans3/=4;
		ans3++;
		int ans4=0; 
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						int sm=(a[i]+a[j]+a[k]+a[l]),maxn=max(a[i],max(a[j],max(a[k],a[l])));
						if(sm>2*maxn) ans4++;
					}
				}
			}
		}
		ans4/=30;
		ans+=ans4;
		int ans5=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						for(int m = 0; m < n; m++){
							if(m==l || m==k || m==j || m==i) continue;
							int sm=(a[i]+a[j]+a[k]+a[l]+a[m]),maxn=max(a[i],max(a[j],max(a[k],max(a[l],a[m]))));
							if(sm>2*maxn) ans5++;
						}
					}
				}
			}
		}
		ans5/=120;
		ans+=ans5;
		int ans6=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						int sm=lsm-a[i]-a[j]-a[k]-a[l],maxn=-114514;
						for(int m = 0; m < n; m++){
							if(m==i || m==j || m==k || m==l) continue;
							maxn=max(maxn,a[m]);
						}
						if(sm>2*maxn) ans6++;
					}
				}
			}
		}
		ans6/=4;
		ans+=ans6;
		int ans7=0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n; k++){
					if(k==i || k==j) continue;
					int sm=lsm-a[i]-a[j]-a[k],maxn=-114514;
					for(int m = 0; m < n; m++){
						if(m==i || m==j || m==k) continue;
						maxn=max(maxn,a[m]);
					}
					if(sm>2*maxn) ans7++;
				}
			}
		}
		ans7/=4;
		ans+=ans7;
		int ans8=0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				int sm=lsm-a[i]-a[j],maxn=-114514;
				for(int m = 0; m < n; m++){
					if(m==i || m==j) continue;
					maxn=max(maxn,a[m]);
				}
				if(sm>2*maxn) ans8++;
			}
		}
		ans8/=2;
		ans+=ans8;
		for(int i = 0; i < n; i++){
			int sm=lsm-a[i],maxn=-114514;
			for(int m = 0; m < n; m++){
				if(m==i) continue;
				maxn=max(maxn,a[m]);
			}
			if(sm>2*maxn) ans++;
		}
		int maxnn=-114514;
		for(int i = 0; i < n; i++){
			maxnn=max(maxnn,a[i]);
		}
		if(lsm>2*maxnn) ans++;
		cout<<ans;
		return 0;
	}
	if(n == 9){
		int lsm=0;
		for(int  i = 0; i < n; i++){
			lsm+=a[i];
		}
		int ans=0,ans3=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					int sm=a[i]+a[j]+a[k],maxn=max(a[i],max(a[j],a[k]));
					if(sm>2*maxn) ans3++;
				}
			}
		}
		ans3/=4;
		ans+=ans3;
		int ans4=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						int sm=(a[i]+a[j]+a[k]+a[l]),maxn=max(a[i],max(a[j],max(a[k],a[l])));
						if(sm>2*maxn) ans4++;
					}
				}
			}
		}
		ans4/=30;
		ans+=ans4;
		int ans5=0;

		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						for(int m = 0; m < n; m++){
							if(m==l || m==k || m==j || m==i) continue;
							int sm=(a[i]+a[j]+a[k]+a[l]+a[m]),maxn=max(a[i],max(a[j],max(a[k],max(a[l],a[m]))));
							if(sm>2*maxn) ans5++;
						}
					}
				}
			}
		}
		ans5/=120;
		int ans6=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						int sm=lsm-a[i]-a[j]-a[k]-a[l],maxn=-114514;
						for(int m = 0; m < n; m++){
							if(m==i || m==j || m==k || m==l) continue;
							maxn=max(maxn,a[m]);
						}
						if(sm>2*maxn) ans6++;
					}
				}
			}
		}
		ans6/=30;
		ans+=ans6;
		int ans7=0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n; k++){
					if(k==i || k==j) continue;
					int sm=lsm-a[i]-a[j]-a[k],maxn=-114514;
					for(int m = 0; m < n; m++){
						if(m==i || m==j || m==k) continue;
						maxn=max(maxn,a[m]);
					}
					if(sm>2*maxn) ans7++;
				}
			}
		}
		ans7/=4;
		ans+=ans7;
		int ans8=0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				int sm=lsm-a[i]-a[j],maxn=-114514;
				for(int m = 0; m < n; m++){
					if(m==i || m==j) continue;
					maxn=max(maxn,a[m]);
				}
				if(sm>2*maxn) ans8++;
			}
		}
		ans8/=2;
		ans+=ans8;
		for(int i = 0; i < n; i++){
			int sm=lsm-a[i],maxn=-114514;
			for(int m = 0; m < n; m++){
				if(m==i) continue;
				maxn=max(maxn,a[m]);
			}
			if(sm>2*maxn) ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n == 8){
		int lsm=0;
		for(int  i = 0; i < n; i++){
			lsm+=a[i];
		}
		int ans=0,ans3=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					int sm=a[i]+a[j]+a[k],maxn=max(a[i],max(a[j],a[k]));
					if(sm>2*maxn) ans3++;
				}
			}
		}
		ans3/=4;
		ans+=ans3;
		int ans4=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						int sm=(a[i]+a[j]+a[k]+a[l]),maxn=max(a[i],max(a[j],max(a[k],a[l])));
						if(sm>2*maxn) ans4++;
					}
				}
			}
		}
		ans4/=30;
		ans+=ans4;
		int ans5=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						for(int m = 0; m < n; m++){
							if(m==l || m==k || m==j || m==i) continue;
							int sm=(a[i]+a[j]+a[k]+a[l]+a[m]),maxn=max(a[i],max(a[j],max(a[k],max(a[l],a[m]))));
							if(sm>2*maxn) ans++;
						}
					}
				}
			}
		}
		ans5/=120;
		ans+=ans5;
		int ans6=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						int sm=lsm-a[i]-a[j]-a[k]-a[l],maxn=-114514;
						for(int m = 0; m < n; m++){
							if(m==i || m==j || m==k || m==l) continue;
							maxn=max(maxn,a[m]);
						}
						if(sm>2*maxn) ans6++;
					}
				}
			}
		}
		ans6/=30;
		ans+=ans6;
		int ans7=0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n; k++){
					if(k==i || k==j) continue;
					int sm=lsm-a[i]-a[j]-a[k],maxn=-114514;
					for(int m = 0; m < n; m++){
						if(m==i || m==j || m==k) continue;
						maxn=max(maxn,a[m]);
					}
					if(sm>2*maxn) ans7++;
				}
			}
		}
		ans7/=4;
		ans+=ans7;
		int ans8=0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				int sm=lsm-a[i]-a[j],maxn=-114514;
				for(int m = 0; m < n; m++){
					if(m==i || m==j) continue;
					maxn=max(maxn,a[m]);
				}
				if(sm>2*maxn) ans8++;
			}
		}
		ans8/=2;
		ans+=ans8;
		cout<<ans;
		return 0;
	}
	if(n == 7){
		int lsm=0;
		for(int  i = 0; i < n; i++){
			lsm+=a[i];
		}
		int ans=0,ans3=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					int sm=a[i]+a[j]+a[k],maxn=max(a[i],max(a[j],a[k]));
					if(sm>2*maxn) ans3++;
				}
			}
		}
		ans3/=4;
		ans+=ans3;
		int ans4=0; 
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						int sm=(a[i]+a[j]+a[k]+a[l]),maxn=max(a[i],max(a[j],max(a[k],a[l])));
						if(sm>2*maxn) ans4++;
					}
				}
			}
		}
		ans4/=30;
		ans+=ans4;
		int ans5=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						for(int m = 0; m < n; m++){
							if(m==l || m==k || m==j || m==i) continue;
							int sm=(a[i]+a[j]+a[k]+a[l]+a[m]),maxn=max(a[i],max(a[j],max(a[k],max(a[l],a[m]))));
							if(sm>2*maxn){
								ans5++;
							}
						}
					}
				}
			}
		}
		ans5/=120;
		ans+=ans5;
		int ans6=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						int sm=lsm-a[i]-a[j]-a[k]-a[l],maxn=-114514;
						for(int m = 0; m < n; m++){
							if(m==i || m==j || m==k || m==l) continue;
							maxn=max(maxn,a[m]);
						}
						if(sm>2*maxn) ans6++;
					}
				}
			}
		}
		ans6/=30;
		ans+=ans6;
		int maxn=max(a[0],max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[6]))))));
		if(lsm>2*maxn) ans++;
		cout<<ans;
		return 0;
	}
	if(n == 6){
		int lsm=0;
		for(int  i = 0; i < n; i++){
			lsm+=a[i];
		}
		int ans=0,ans3=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					int sm=a[i]+a[j]+a[k],maxn=max(a[i],max(a[j],a[k]));
					if(sm>2*maxn) ans3++;
				}
			}
		}
		ans3/=4;
		ans+=ans3;
		int ans4=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						int sm=(a[i]+a[j]+a[k]+a[l]),maxn=max(a[i],max(a[j],max(a[k],a[l])));
						if(sm>2*maxn) ans4++;
					}
				}
			}
		}
		ans4/=30;
		ans+=ans4;
		int ans5=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						for(int m = 0; m < n; m++){
							if(m==l || m==k || m==j || m==i) continue;
							int sm=(a[i]+a[j]+a[k]+a[l]+a[m]),maxn=max(a[i],max(a[j],max(a[k],max(a[l],a[m]))));
							if(sm>2*maxn) ans5++;
						}
					}
				}
			}
		}
		ans5/=120;
		int ans6=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						int sm=lsm-a[i]-a[j]-a[k]-a[l],maxn=-114514;
						for(int m = 0; m < n; m++){
							if(m==i || m==j || m==k || m==l) continue;
							maxn=max(maxn,a[m]);
						}
						if(sm>2*maxn) ans6++;
					}
				}
			}
		}
		ans6/=30;
		ans+=ans6;
		cout<<ans;
		return 0;
	}
	if(n == 5){
		int lsm=0;
		for(int  i = 0; i < n; i++){
			lsm+=a[i];
		}
		int ans=0,ans3=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					int sm=a[i]+a[j]+a[k],maxn=max(a[i],max(a[j],a[k]));
					if(sm>2*maxn){
						ans3++;
					}
				}
			}
		}
		ans3/=4;
		ans+=ans3;
		int ans4=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					for(int l = 0; l < n; l++){
						if(l==k || l==j || l==i) continue;
						int sm=(a[i]+a[j]+a[k]+a[l]),maxn=max(a[i],max(a[j],max(a[k],a[l])));
						if(sm>2*maxn){
							ans4++;
						}
					}
				}
			}
		}
		ans4/=30;
		ans+=ans4;
		int maxn=max(a[0],max(a[1],max(a[2],max(a[3],a[4]))));
		if(lsm>2*maxn) ans++;
		cout<<ans;
		return 0;
	}
	if(n == 4){
		int lsm=0;
		for(int  i = 0; i < n; i++){
			lsm+=a[i];
		}
		int ans=0,ans3=0;
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				for(int k = 0; k < n;k++){
					if(k==i || k==j) continue;
					int sm=a[i]+a[j]+a[k],maxn=max(a[i],max(a[j],a[k]));
					if(sm>2*maxn) ans3++;
				}
			}
		}
		ans3/=4;
		ans+=ans3;
		int maxn=max(a[0],max(a[1],max(a[2],a[3])));
		if(lsm>2*maxn) ans++;
		cout<<ans;
		return 0;
	}
	return 0;
}