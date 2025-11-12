#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct k{
	ll xh=0,grade=0,club;
};
bool cmp(k a,k b){
	return a.grade>b.grade;
}
bool cnm(k a,k b){
	if(a.club==1&&b.club!=1)return false;
	return a.grade>b.grade;
}bool wnm(k a,k b){
	if(a.club==2&&b.club!=2)return false;
	return a.grade>b.grade;
}bool snm(k a,k b){
	if(a.club==3&&b.club!=3)return false;
	return a.grade>b.grade;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll ks;
	cin>>ks;
	while(ks--){
		vector<k> l;
		ll n,x,ans2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>x;
				k d;
				d.grade=x;
				d.xh=i;
				d.club=j;
				l.push_back(d);
			}
		}sort(l.begin(),l.end(),cmp);
		vector<k> p=l;
		for(int i=0;i<=n;i++){
			ll s=i,ans=0,fl[]={0,0,0,0,0,0},cl[]={0,0,0,0,0,0};
			map<ll,ll> flag;
			l=p;
			while(s<l.size()){
				if(flag[l[s].xh]==0&&fl[l[s].club]==0){
					flag[l[s].xh]=1;
					cl[l[s].club]++;
					ans+=l[s].grade;
					if(cl[l[s].club]==n/2){
						fl[l[s].club]=1;
						if(l[s].club==1){
							sort(l.begin(),l.end(),cnm);}
						else if(l[s].club==1){
							sort(l.begin(),l.end(),wnm);}
						else sort(l.begin(),l.end(),snm);
					}
				}s++;
			}s=0;
			while(s<l.size()){
				if(flag[l[s].xh]==0&&fl[l[s].club]==0){
					flag[l[s].xh]=1;
					cl[l[s].club]++;
					ans+=l[s].grade;
					if(cl[l[s].club]==n/2){
						fl[l[s].club]=1;
						if(l[s].club==1){
							sort(l.begin(),l.end(),cnm);}
						else if(l[s].club==1){
							sort(l.begin(),l.end(),wnm);}
						else sort(l.begin(),l.end(),snm);
					}
				}s++;
			}
			ans2=max(ans2,ans);
		}cout<<ans2<<endl;
	}
}