#include<bits/stdc++.h>
using namespace std;
long long T,n,a,b,c,acnt1=0,acnt2=0,acnt3=0,ans=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,cnt6=0,cnt7=0,cnt8=0,cnt9=0;
struct node{
	bool vis;
};
struct ac{
	long long z,i;
};
bool cmp(ac i,ac j){
	if(i.z>=j.z){
		return i.z>j.z;
	}else{
		return i.z<j.z;
	}
}
ac a1[100005],a2[100005],a3[100005],b1[100005],b2[100005],b3[100005],c1[100005],c2[100005],c3[100005];
node m[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		acnt1=0,acnt2=0,acnt3=0,ans=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,cnt6=0,cnt7=0,cnt8=0,cnt9=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			m[i].vis=false;
			if(a>=b&&a>=c){
				cnt1++;
				a1[cnt1].z=a;
				a1[cnt1].i=i;
				if(b>=c){
					cnt5++;
					b2[cnt5].z=b;
					b2[cnt5].i=i;
					cnt9++;
					c3[cnt9].z=c;
					c3[cnt9].i=i;
				}else{
					cnt8++;
					c2[cnt8].z=c;
					c2[cnt8].i=i;
					cnt6++;
					b3[cnt6].z=b;
					b3[cnt6].i=i;
				}
			}else if(b>=a&&b>=c){
				cnt4++;
				b1[cnt4].z=b;
				b1[cnt4].i=i;
				if(a>=c){
					cnt2++;
					a2[cnt2].z=a;
					a2[cnt2].i=i;
					cnt9++;
					c3[cnt9].z=c;
					c3[cnt9].i=i;
				}else{
					cnt8++;
					c2[cnt8].z=c;
					c2[cnt8].i=i;
					cnt3++;
					a3[cnt3].z=a;
					a3[cnt3].i=i;
				}
			}else if(c>=a&&c>=b){
				cnt7++;
				c1[cnt7].z=c;
				c1[cnt7].i=i;
				if(b>=a){
					cnt5++;
					b2[cnt5].z=b;
					b2[cnt5].i=i;
					cnt3++;
					a3[cnt3].z=a;
					a3[cnt3].i=i;
				}else{
					cnt2++;
					a2[cnt2].z=a;
					a2[cnt2].i=i;
					cnt6++;
					b3[cnt6].z=b;
					b3[cnt6].i=i;
				}
			}
		}
		sort(a1+1,a1+cnt1+1,cmp);
		sort(a2+1,a2+cnt2+1,cmp);
		sort(a3+1,a3+cnt3+1,cmp);
		sort(b1+1,b1+cnt4+1,cmp);
		sort(b2+1,b2+cnt5+1,cmp);
		sort(b3+1,b3+cnt6+1,cmp);
		sort(c1+1,c1+cnt7+1,cmp);
		sort(c2+1,c2+cnt8+1,cmp);
		sort(c3+1,c3+cnt9+1,cmp);
		if(cnt1<=n/2){
			for(int i=1;i<=cnt1;i++){
				ans+=a1[i].z;
				m[a1[i].i].vis=true;
			}
			acnt1+=cnt1;
		}else{
			for(int i=1;i<=n/2;i++){
				ans+=a1[i].z;
				m[a1[i].i].vis=true;
			}
			acnt1=n/2;
		}
		if(cnt4<=n/2){
			for(int i=1;i<=cnt4;i++){
				ans+=b1[i].z;
				m[b1[i].i].vis=true;
			}
			acnt2+=cnt4;
		}else{
			for(int i=1;i<=n/2;i++){
				ans+=b1[i].z;
				m[b1[i].i].vis=true;
			}
			acnt2=n/2;
		}
		if(cnt7<=n/2){
			for(int i=1;i<=cnt7;i++){
				ans+=c1[i].z;
				m[c1[i].i].vis=true;
			}
			acnt3+=cnt7;
		}else{
			for(int i=1;i<=n/2;i++){
				ans+=c1[i].z;
				m[c1[i].i].vis=true;
			}
			acnt3=n/2;
		}
		if(acnt1<n/2){
			if(cnt2<=n/2-acnt1){
				int g=0;
				for(int i=1;i<=cnt2;i++){
					if(!m[a2[i].i].vis){
						ans+=a2[i].z;
						g++;
						m[a2[i].i].vis=true;
					}
				}
				acnt1+=g;
			}else{
				int g=0;
				for(int i=1;i<=n/2-acnt1;i++){
					if(!m[a2[i].i].vis){
						ans+=a2[i].z;
						g++;
						m[a2[i].i].vis=true;
					}
				}
				acnt1+=g;
			}
		}
		if(acnt2<n/2){
			if(cnt5<=n/2-acnt2){
				int g=0;
				for(int i=1;i<=cnt5;i++){
					if(!m[b2[i].i].vis){
						ans+=b2[i].z;
						g++;
						m[b2[i].i].vis=true;
					}
				}
				acnt2+=g;
			}else{
				int g=0;
				for(int i=1;i<=n/2-acnt2;i++){
					if(!m[b2[i].i].vis){
						ans+=b2[i].z;
						g++;
						m[b2[i].i].vis=true;
					}
				}
				acnt2+=g;
			}
		}
		if(acnt3<n/2){
			if(cnt8<=n/2-acnt3){
				int g=0;
				for(int i=1;i<=cnt8;i++){
					if(!m[c2[i].i].vis){
						ans+=c2[i].z;
						g++;
						m[c2[i].i].vis=true;
					}
				}
				acnt3+=g;
			}else{
				int g=0;
				for(int i=1;i<=n/2-acnt3;i++){
					if(!m[c2[i].i].vis){
						ans+=c2[i].z;
						g++;
						m[c2[i].i].vis=true;
					}
				}
				acnt3+=g;
			}
		}
		
		if(acnt1<n/2){
			for(int i=1,j=1;i<=n/2-acnt1;j++){
				if(!m[a3[j].i].vis){
					i++;
					ans+=a3[j].z;
				}
				if(j>=cnt3){
					break;
				}
			}
		}
		
		if(acnt2<n/2){
			for(int i=1,j=1;i<=n/2-acnt2;j++){
				if(!m[b3[j].i].vis){
					i++;
					ans+=b3[j].z;
				}
				if(j>=cnt6){
					break;
				}
			}
		}
		
		if(acnt3<n/2){
			for(int i=1,j=1;i<=n/2-acnt3;j++){
				if(!m[c3[j].i].vis){
					i++;
					ans+=c3[j].z;
				}
				if(j>=cnt9){
					break;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
