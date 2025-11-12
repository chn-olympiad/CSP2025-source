//GZ-S00096 周一笑 白云区实验中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
int m,n,su;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	while(m--){
		int a[N],b[N],c[N];
		bool f[N]={0};
		su=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(f[i]) continue;
			f[i]=1;
			if(a[i]>b[i] && a[i]>c[i]){
				su+=a[i];
			}else if(b[i]>a[i] && b[i]>c[i]){
				su+=b[i];
			}else if(c[i]>a[i] && c[i]>b[i]){ 
				su+=c[i];
			}
		}
		cout<<su<<endl;
	}
	

	return 0;
}




