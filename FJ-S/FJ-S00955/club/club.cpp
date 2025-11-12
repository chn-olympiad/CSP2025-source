#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],asdf;
int sa[100005],sb[100005],sc[100005],ad=1,bd=1,cd=1;
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ad=1;bd=1;cd=1;ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				if(ad<=n/2){
					sa[ad]=i;
					ad++;
				}else{
					asdf=1;
					for(int j=1;j<ad;j++){
						if(b[sa[j]]>c[sa[j]]&&a[i]>a[sa[j]]){
							sb[bd++]=sa[j];
							sa[j]=i;
							asdf=0;
						}else if(a[i]>a[sa[j]]){
							sc[cd++]=sa[j];
							sa[j]=i;
							asdf=0;
						}
					}if(asdf==1&&b[i]>c[i])b[bd++]=i;
					else c[cd++]=i;
				}
			}else if(b[i]>c[i]){
				if(bd<=n/2){
					sb[bd++]=i;
				}else{
					asdf=1;
					for(int j=1;j<bd;j++){
						if(a[sb[j]]>c[sb[j]]&&b[i]>b[sb[j]]){
							sa[ad++]=sb[j];
							sb[j]=i;
							asdf=0;
						}else if(b[i]>b[sb[j]]){
							sc[cd++]=sb[j];
							sb[j]=i;
							asdf=0;
						}
					}if(asdf==1&&a[i]>c[i])a[ad++]=i;
					else c[cd++]=i;
				}
			}else{
				if(cd<=n/2){
					sc[cd++]=i;
				}else{
					asdf=1;
					for(int j=1;j<cd;j++){
						if(b[sc[j]]>a[sc[j]]&&c[i]>c[sc[j]]){
							sb[bd++]=sc[j];
							sc[j]=i;
							asdf=0;
						}else if(a[i]>b[sc[j]]){
							sa[ad++]=sc[j];
							sc[j]=i;
							asdf=0;
						}
					}if(asdf==1&&a[i]>b[i])a[ad++]=i;
					else b[bd++]=i;
				}
			}
		}for(int i=1;i<ad;i++){
			ans+=a[sa[i]];
		}for(int i=1;i<bd;i++){
			ans+=b[sb[i]];
		}for(int i=1;i<cd;i++){
			ans+=c[sc[i]];
		}cout<<ans<<endl;
	}
	return 0;
} 
