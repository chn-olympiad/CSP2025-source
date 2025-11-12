#include<bits/stdc++.h>
using namespace std;
struct ct{
	int a[5],t1,t2,t3,t4,ma,mi,md;
}s[100005];
int cmp(ct s1,ct s2){
	if(s1.t2==s2.t2&&s1.t3==s2.t3){
		return s1.t4>s2.t4;
	}
	if(s1.t2==s2.t2){
		return s1.t3>s2.t3;
	}
	return s1.t2>s2.t2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int f[5]={0,0,0,0,0};
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
			s[i].t1=i;
			s[i].t2=max(s[i].a[1],max(s[i].a[2],s[i].a[3]));
			if(s[i].a[1]>s[i].a[2]&&s[i].a[1]>s[i].a[3]){
				s[i].ma=1;
			}else if(s[i].a[2]>s[i].a[1]&&s[i].a[2]>s[i].a[3]){
				s[i].ma=2;
			}else if(s[i].a[3]>s[i].a[2]&&s[i].a[1]<s[i].a[3]){
				s[i].ma=3;
			}
			if(s[i].a[1]>s[i].a[2]&&s[i].a[1]<s[i].a[3]||s[i].a[1]<s[i].a[2]&&s[i].a[1]>s[i].a[3]){
				s[i].md=1;s[i].t3=s[i].a[1];
			}else if(s[i].a[2]>s[i].a[1]&&s[i].a[2]<s[i].a[3]||s[i].a[2]<s[i].a[1]&&s[i].a[2]>s[i].a[3]){
				s[i].md=2;s[i].t3=s[i].a[2];
			}else if(s[i].a[3]>s[i].a[2]&&s[i].a[3]<s[i].a[1]||s[i].a[3]<s[i].a[1]&&s[i].a[3]>s[i].a[1]){
				s[i].md=3;s[i].t3=s[i].a[3];
			}
			if(s[i].a[1]<s[i].a[2]&&s[i].a[1]<s[i].a[3]){
				s[i].mi=1;s[i].t4=s[i].a[1];
			}else if(s[i].a[2]<s[i].a[1]&&s[i].a[2]<s[i].a[3]){
				s[i].mi=2;s[i].t4=s[i].a[2];
			}else if(s[i].a[3]<s[i].a[2]&&s[i].a[1]>s[i].a[3]){
				s[i].mi=3;s[i].t4=s[i].a[3];
			}
		}
		int x=n/2,sum=0;
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(s[i].ma==1){
				if(f[s[i].ma]<=x){
					sum+=s[i].a[s[i].ma];
					f[s[i].ma]++;
				}else if(s[i].md<=x){
					sum+=s[i].a[s[i].md];
					f[s[i].md]++;
				}else{
					sum+=s[i].a[s[i].mi];
					f[s[i].mi]++;
				}
			}else if(s[i].ma==2){
				if(f[s[i].ma]!=x){
					sum+=s[i].a[s[i].ma];
					f[s[i].ma]++;
				}else if(s[i].md!=x){
					sum+=s[i].a[s[i].md];
					f[s[i].md]++;
				}else{
					sum+=s[i].a[s[i].mi];
					f[s[i].mi]++;
				}
			}else{
				if(f[s[i].ma]!=x){
					sum+=s[i].a[s[i].ma];
					f[s[i].ma]++;
				}else if(s[i].md!=x){
					sum+=s[i].a[s[i].md];
					f[s[i].md]++;
				}else{
					sum+=s[i].a[s[i].mi];
					f[s[i].mi]++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
