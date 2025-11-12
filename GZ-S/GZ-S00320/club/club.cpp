//GZ-S00320 贵阳市第一中学 王文彬
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],c[100005],ans,d[20010],l;
int f=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int p=1;p<=n;p++){
		for(int i=1;i<=m;i++){
			a[i]=0;
			b[i]=0;
			c[i]=0;

		}
		for(int i=20005;i>=0;i--){
			d[i]=0;
		}
		f=0;
		ans=0;
		int aa=0,bb=0,cc=0,mmax=0;
		cin>>m;
		int mm=m/2;
		for(int i=1;i<=m;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0){
				f=1;
			}
		}
		if(f==0){
			for(int i=1;i<=m;i++){
				d[a[i]]++;
			}
			for(int i=20005;i>=0;i--){
				if(d[i]==0){
					continue;
				}
				if(mm<d[i]){
					ans+=mm*d[i];
					cout<<ans<<endl;
					break;
				}
				else{
					ans+=i*d[i];
					mm-=d[i];
				}
			}
		}
		else{
			for(int i=1;i<=m;i++){
				mmax=0;
				aa=0;
				bb=0;
				cc=0;
				for(int j=i;j<m+i;j++){

					if(j>m) l=j-m;
					else l=j;

					if(a[l]>=b[l]&&a[l]>=c[l]){
						if(aa==m/2){
							mmax+=max(b[l],c[l]);
						}
						else{
							mmax+=a[l];
							aa++;
						}

					}
					else if(b[l]>=a[l]&&b[l]>=c[l]){
						if(bb==m/2){
							mmax+=max(a[l],c[l]);
						}
						else{
							mmax+=b[l];
							bb++;
						}

					}
					else{
						if(cc==m/2){
							mmax+=max(b[l],a[l]);
						}
						else{
							mmax+=c[l];
							cc++;
						}

					}
				}
				ans=max(ans,mmax);
			}

			cout<<ans<<endl;
		}
	}
	return 0;
	//GG 三小时十分到手(骗你的可能十分都没有)
}

