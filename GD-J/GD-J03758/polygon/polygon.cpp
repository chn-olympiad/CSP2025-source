#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,o[5010],cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>o[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			for(ll l=j+1;l<=n;l++){
				for(ll a=l+1;a<=n;a++){
					for(ll b=a+1;b<=n;b++){
						for(ll c=b+1;c<=n;c++){
							for(ll d=c+1;d<=n;d++){
								for(ll e=d+1;e<=n;e++){
									for(ll f=e+1;f<=n;f++){
										for(ll g=f+1;g<=n;g++){
											if(o[i]+o[j]+o[l]+o[a]+o[b]+o[c]+o[d]+o[e]+o[f]+o[g]>2*max(o[i],max(o[j],max(o[l],max(o[a],max(o[b],max(o[c],max(o[d],max(o[e],max(o[f],o[g]))))))))))cnt++,cnt%=998244353;
										}
										if(o[i]+o[j]+o[l]+o[a]+o[b]+o[c]+o[d]+o[e]+o[f]>2*max(o[i],max(o[j],max(o[l],max(o[a],max(o[b],max(o[c],max(o[d],max(o[e],o[f])))))))))cnt++,cnt%=998244353;
									}
									if(o[i]+o[j]+o[l]+o[a]+o[b]+o[c]+o[d]+o[e]>2*max(o[i],max(o[j],max(o[l],max(o[a],max(o[b],max(o[c],max(o[d],o[e]))))))))cnt++,cnt%=998244353;
								}
								if(o[i]+o[j]+o[l]+o[a]+o[b]+o[c]+o[d]>2*max(o[i],max(o[j],max(o[l],max(o[a],max(o[b],max(o[c],o[d])))))))cnt++,cnt%=998244353;
							}
							if(o[i]+o[j]+o[l]+o[a]+o[b]+o[c]>2*max(o[i],max(o[j],max(o[l],max(o[a],max(o[b],o[c]))))))cnt++,cnt%=998244353;
						}
						if(o[i]+o[j]+o[l]+o[a]+o[b]>2*max(o[i],max(o[j],max(o[l],max(o[a],o[b])))))cnt++,cnt%=998244353;
					}
					if(o[i]+o[j]+o[l]+o[a]>2*max(o[i],max(o[j],max(o[l],o[a]))))cnt++,cnt%=998244353;
				}
				if(o[i]+o[j]+o[l]>2*max(o[i],max(o[j],o[l])))cnt++,cnt%=998244353;
			}
			if(o[i]+o[j]>2*max(o[i],o[j]))cnt++,cnt%=998244353;
		}
		if(o[i]>2*o[i])cnt++,cnt%=998244353;
	}
	cout<<cnt;
	return 0;
}
