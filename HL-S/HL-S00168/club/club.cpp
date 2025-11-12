#include<bits/stdc++.h>
using namespace std;
struct tun{
	long long a;
	long long b;
	long long c;
	long long number;
	long long first;
	long long second;
	long long less;
}s[100005];
bool cmp(tun a,tun b){
	return a.less<b.less;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long lesssum=0;
		long long ans=0;
		long long anum=0;
		long long bnum=0;
		long long cnum=0;
		long long  n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].first=max(max(s[i].a,s[i].b),s[i].c);
			s[i].second=s[i].a+s[i].b+s[i].c-s[i].first-min(min(s[i].a,s[i].b),s[i].c);
			if(s[i].first==s[i].a){
				anum++;
			}
			else if(s[i].first==s[i].b){
				bnum++;
			}
			else{
				cnum++;
			}
			s[i].number=i;
			s[i].less=s[i].first-s[i].second;
		}
		for(int i=0;i<n;i++){
			ans+=s[i].first;
		}
		if(anum<=n/2&&bnum<=n/2&&cnum<=n/2){
			cout<<ans;
			continue;
		}
		else{
			int numb=max(anum,max(bnum,cnum))-n/2;
			sort(s,s+n,cmp);
			if(bnum>n/2){
				for(int i=0;i<n;i++){
					if(s[i].first==s[i].b){
						lesssum+=s[i].less;
						numb--;
					}
					if(numb==0){
						break;
					}
				}
			}
			else if(anum>n/2){
				for(int i=0;i<n;i++){
					if(s[i].first==s[i].a){
						lesssum+=s[i].less;
						numb--;
					}
					if(numb==0){
						break;
					}
				}
			}
			else{
				for(int i=0;i<n;i++){
					if(s[i].first==s[i].b){
						lesssum+=s[i].less;
						numb--;
					}
						if(numb==0){
							break;
						}
					}
			}
			cout<<ans-lesssum;
			}
	}
	
	return 0;
}