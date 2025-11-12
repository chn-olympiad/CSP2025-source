#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll a[N][5],n,_,f[5];// f[5]->最大值数量（防 n/2）
ll ans=0,maxxn,cha1[N],cha2[N],cha3[N];
ll i1=0,i2=0,i3=0;

ll more1(ll a){
	ll sum=0;
	for(int i=1;i<=f[a]-n/2;i++){
		sum+=cha1[i];
	}
	return sum;
}
ll more2(ll a){
	ll sum=0;
	for(int i=1;i<=f[a]-n/2;i++){
		sum+=cha2[i];
	}
	return sum;
}
ll more3(ll a){
	ll sum=0;
	for(int i=1;i<=f[a]-n/2;i++){
		sum+=cha3[i];
	}
	return sum;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--){
        memset(f,0,sizeof(f));
		memset(cha1,0,sizeof(cha1));i1=0;
        memset(cha2,0,sizeof(cha2));i2=0;
        memset(cha3,0,sizeof(cha3));i3=0;
		ans=0; cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				maxxn=1; i1++;
				cha1[i1]=a[i][1]-max(a[i][2],a[i][3]);
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				maxxn=2; i2++;
				cha2[i2]=a[i][2]-max(a[i][1],a[i][3]);
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				maxxn=3;i3++;
				cha3[i3]=a[i][3]-max(a[i][2],a[i][1]);
			}f[maxxn]++;
			ans+=a[i][maxxn];
		}

		sort(cha1+1,cha1+1+i1);
		sort(cha2+1,cha2+1+i2);
		sort(cha3+1,cha3+1+i3);

		if(f[1] > n/2) cout<<ans-more1(1)<<endl;
		else if(f[2] > n/2) cout<<ans-more2(2)<<endl;
		else if(f[3] > n/2){
                cout<<ans-more3(3)<<endl;
		}
		else cout<<ans<<endl;
	}
	return 0;
}
