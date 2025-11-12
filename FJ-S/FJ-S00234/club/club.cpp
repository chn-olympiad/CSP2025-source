#include<bits/stdc++.h>
using namespace std;
int a[100010][3],f[100010],u;
struct node{
	int a[3],s;
}b[100010];
int cmp(node x,node y){
	return x.a[u]-x.s<y.a[u]-y.s;
}
int T,n,cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cnt=0;
		memset(f,0,sizeof(f));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		long long s1=0,s2=0,s3=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
				f[i]=0;
				ans+=a[i][0];
				s1++;
			}else if(a[i][1]>a[i][2]){
				f[i]=1;
				ans+=a[i][1];
				s2++;
			}else{
				f[i]=2;
				ans+=a[i][2];
				s3++;
			}
		}
		if(s1>n/2){
			u=0;
			for(int i=1;i<=n;i++){
				if(f[i]==u){
					b[++cnt].a[0]=a[i][0];
					b[cnt].a[1]=a[i][1];
					b[cnt].a[2]=a[i][2];
					b[cnt].s=max(a[i][1],a[i][2]);
				}
			}
//			if(s1!=cnt)cout<<"E1";
			sort(b+1,b+1+cnt,cmp);
			for(int i=1;i<=cnt-n/2;i++){
				ans-=(b[i].a[u]-b[i].s);
			}
		}
		if(s2>n/2){
			u=1;
			for(int i=1;i<=n;i++){
				if(f[i]==u){
					b[++cnt].a[0]=a[i][0];
					b[cnt].a[1]=a[i][1];
					b[cnt].a[2]=a[i][2];
					b[cnt].s=max(a[i][0],a[i][2]);
				}
			}
			sort(b+1,b+1+cnt,cmp);
			for(int i=1;i<=cnt-n/2;i++){
				ans-=(b[i].a[u]-b[i].s);
			}
//			if(s2!=cnt)cout<<"E2";
		}
		if(s3>n/2){
			u=2;
			for(int i=1;i<=n;i++){
				if(f[i]==u){
					b[++cnt].a[0]=a[i][0];
					b[cnt].a[1]=a[i][1];
					b[cnt].a[2]=a[i][2];
					b[cnt].s=max(a[i][1],a[i][0]);
				}
			}
			sort(b+1,b+1+cnt,cmp);
			for(int i=1;i<=cnt-n/2;i++){
				ans-=(b[i].a[u]-b[i].s);
			}
//			if(s3!=cnt)cout<<"E3";
		}
//		cout<<n<<" "<<s1<<" "<<s2<<" "<<s3<<" "<<cnt<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
