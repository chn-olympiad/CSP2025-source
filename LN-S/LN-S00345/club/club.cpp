#include<bits/stdc++.h>
namespace test{
	constexpr int N=1e5+5;
	int a1[N],a2[N],a3[N];
	int cnt1,cnt2,cnt3;bool flag;
	bool comp(int x,int y){
		return x>y;
	};
	void main(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		cnt1=cnt2=0,flag=0;
		int n;
		std::cin>>n;
		for(int i=1;i<=n;++i){std::cin>>a1[i]>>a2[i]>>a3[i];flag|=((a3[i]!=0)|(a2[i]!=0));}
		int ans=0;
		if(flag==0){
			std::sort(a1+1,a1+n+1,comp);
			for(int i=1;i<=n/2;++i)ans+=a1[i];
			std::cout<<ans<<'\n';
		}
		else{
			for(int i=1;i<=n;++i){
				int ma=std::max({a1[i],a2[i],a3[i]}),mid=a1[i]+a2[i]+a3[i]-std::max({a1[i],a2[i],a3[i]})-std::min({a1[i],a2[i],a3[i]});
				//std::cerr<<ma<<'\n';
				if(a1[i]==ma){
					if(cnt1<n/2)cnt1++,ans+=ma;
					else if(a2[i]==mid)cnt2++,ans+=mid;
					else cnt3++,ans+=mid;
				}
				else if(a2[i]==ma){
					if(cnt2<n/2)cnt2++,ans+=ma;
					else if(a1[i]==mid)cnt1++,ans+=mid;
					else cnt3++,ans+=mid;
				}
				else{
					if(cnt3<n/2)cnt3++,ans+=ma;
					else if(a1[i]==mid)cnt1++,ans+=mid;
					else cnt2++,ans+=mid;
				}
			}
			std::cout<<ans<<'\n';
		}
	}
}
int main(){
	int T;std::cin>>T;
	while(T--)test::main();
	return 0;
}