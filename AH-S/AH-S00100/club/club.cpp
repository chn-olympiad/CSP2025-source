#include<bits/stdc++.h>
using namespace std;
	int t,n,m,num,ans;
struct node{
	int a[3];
}f[200000];
int b[3];
bool cmp(node x,node y){
	return x.a[(m+2)%3]<y.a[(m+2)%3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;num=0;ans=0;
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&f[i].a[0],&f[i].a[1],&f[i].a[2]);
			num=max(f[i].a[0],max(f[i].a[1],f[i].a[2]));
			ans+=num;
			for(int j=0;j<3;j++)
				if (num==f[i].a[j]){b[j]++;break;}
		}
		num=max(b[0],max(b[1],b[2]));
		if (num<n/2) {
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<3;i++)
			if (num==b[i]){
					m=i;break;
				}
		for(int i=0;i<n;i++){
			f[i].a[(m+1)%3]=max(f[i].a[(m+1)%3],f[i].a[(m+2)%3]);
			f[i].a[(m+2)%3]=f[i].a[m]-f[i].a[(m+1)%3];
		}
		sort(f,f+n,cmp);
	ans=0;
	for(int i=0;i<n;i++){
		if (i<n/2) ans+=f[i].a[(m+1)%3];
		else ans+=f[i].a[m];
	}
	cout<<ans<<endl;
	}
	
	return 0;
}
