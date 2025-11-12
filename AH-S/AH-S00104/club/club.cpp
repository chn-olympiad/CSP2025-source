#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	 ll stt,ndd,rdd;
	 ll st,nd,rd;
}a[100005];
struct aaa{
	ll n1,n2,n3;
	long long s1[100005],s2[100005],s3[100005];
}xz;
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			ll i1,i2,i3,fl=0,ag=0;
			cin>>i1>>i2>>i3;
			a[i].st=max(max(i1,i2),i3);
			if(a[i].st==i1 && !fl){a[i].stt=1;fl=1;}
			else if(a[i].st==i2 && !ag){a[i].stt=2;ag=1;}
			else a[i].stt=3;
			
			a[i].nd=i1+i2+i3-max(max(i1,i2),i3)-min(min(i1,i2),i3);
			if(a[i].nd==i1&& !fl){a[i].ndd=1;fl=1;}
			else if(a[i].nd==i2&& !ag){a[i].ndd=2;ag=1;}
			else a[i].ndd=3;
			
			a[i].rd=min(min(i1,i2),i3);
			if(a[i].rd==i1&& !fl){a[i].rdd=1;fl=1;}
			else if(a[i].rd==i2&& !ag){a[i].rdd=2;ag=1;}
			else a[i].rdd=3;
		}
		xz.n1=0;
		xz.n2=0;
		xz.n3=0;
		for(int i=1;i<=n;i++){
			if(a[i].stt==1){
				if(xz.n1==n/2){
					xz.s1[++xz.n1]=i;
					ll minn=1e12,at=0,nuu;
					for(int j=1;j<=xz.n1;j++){
						if(a[xz.s1[j]].stt==1){
							if(a[xz.s1[j]].st-a[xz.s1[j]].nd<minn){
								minn=a[xz.s1[j]].st-a[xz.s1[j]].nd;
								at=j;
								nuu=1;
							}
						}
						else if(a[xz.s1[j]].ndd==1){
							if(a[xz.s1[j]].nd-a[xz.s1[j]].rd<minn){
								minn=a[xz.s1[j]].nd-a[xz.s1[j]].rd;
								at=j;
								nuu=2;
							}
						}
						else continue;
					}
					if(nuu==1){
						if(a[xz.s1[at]].ndd==2){
							xz.s2[++xz.n2]=xz.s1[at];
						}
						else {
							xz.s3[++xz.n3]=xz.s1[at];
						}
					}
					else{
						if(a[xz.s1[at]].rdd==2){
							xz.s2[++xz.n2]=xz.s1[at];
						}
						else {
							xz.s3[++xz.n3]=xz.s1[at];
						}
					}
					xz.s1[at]=xz.s1[xz.n1];
					xz.n1--;
				}
				else {
					xz.s1[++xz.n1]=i;
				}
			}
			else if(a[i].stt==2){
				if(xz.n2==n/2){
					xz.s2[++xz.n2]=i;
					ll minn=1e12,at=0,nuu;
					for(int j=1;j<=xz.n2;j++){
						if(a[xz.s2[j]].stt==2){
							if(a[xz.s2[j]].st-a[xz.s2[j]].nd<minn){
								minn=a[xz.s2[j]].st-a[xz.s2[j]].nd;
								at=j;
								nuu=1;
							}
						}
						else if(a[xz.s2[j]].ndd==2){
							if(a[xz.s2[j]].nd-a[xz.s2[j]].rd<minn){
								minn=a[xz.s2[j]].nd-a[xz.s2[j]].rd;
								at=j;
								nuu=2;
							}
						}
						else continue;
					}
					if(nuu==1){
						if(a[xz.s2[at]].ndd==1){
							xz.s1[++xz.n1]=xz.s2[at];
						}
						else {
							xz.s3[++xz.n3]=xz.s2[at];
						}
					}
					else{
						if(a[xz.s2[at]].rdd==1){
							xz.s1[++xz.n1]=xz.s2[at];
							
						}
						else {
							xz.s3[++xz.n3]=xz.s2[at];
						}
					}
					xz.s2[at]=xz.s2[xz.n2];
					xz.n2--;
				}
				else {
					xz.s2[++xz.n2]=i;
				}
			}
			else{
				if(xz.n3==n/2){
					xz.s3[++xz.n3]=i;
					ll minn=1e12,at=0,nuu;
					for(int j=1;j<=xz.n3;j++){
						if(a[xz.s3[j]].stt==3){
							if(a[xz.s3[j]].st-a[xz.s3[j]].nd<minn){
								minn=a[xz.s3[j]].st-a[xz.s3[j]].nd;
								at=j;
								nuu=1;
							}
						}
						else if(a[xz.s3[j]].ndd==3){
							if(a[xz.s3[j]].nd-a[xz.s3[j]].rd<minn){
								minn=a[xz.s3[j]].nd-a[xz.s3[j]].rd;
								at=j;
								nuu=2;
							}
						}
					}
					if(nuu==1){
						if(a[xz.s3[at]].ndd==2){
							xz.s2[++xz.n2]=xz.s3[at];
						}
						else {
							xz.s1[++xz.n1]=xz.s3[at];
						}
					}
					else{
						if(a[xz.s3[at]].rdd==2){
							xz.s2[++xz.n2]=xz.s3[at];
						}
						else {
							xz.s1[++xz.n1]=xz.s3[at];
						}
					}
					xz.s3[at]=xz.s3[xz.n3];
					xz.n3--;
				}
				else {
					xz.s3[++xz.n3]=i;
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=xz.n1;i++){
			if(a[xz.s1[i]].stt==1){
				ans+=a[xz.s1[i]].st;
			}
			else if(a[xz.s1[i]].ndd==1){
				ans+=a[xz.s1[i]].nd;
			}
			else ans+=a[xz.s1[i]].rd;
			//cout<<xz.s1[i]<<" 1 ";
		}
		for(int i=1;i<=xz.n3;i++){
			if(a[xz.s3[i]].stt==3){
				ans+=a[xz.s3[i]].st;
			}
			else if(a[xz.s3[i]].ndd==3){
				ans+=a[xz.s3[i]].nd;
			}
			else ans+=a[xz.s3[i]].rd;
			//cout<<xz.s3[i]<<" 3 ";
		}
		for(int i=1;i<=xz.n2;i++){
			if(a[xz.s2[i]].stt==2){
				ans+=a[xz.s2[i]].st;
			}
			else if(a[xz.s2[i]].ndd==2){
				ans+=a[xz.s2[i]].nd;
			}
			else ans+=a[xz.s2[i]].rd;
			//cout<<xz.s2[i]<<" 2 ";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
