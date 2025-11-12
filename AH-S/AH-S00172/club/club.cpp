#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[100009],b[100009],c[100009],z[100009];
int ans;
void smallswaper(int a[100009],int b[100009],int c[100009],int z[100009],int q,int p){
	for(int i=q;i<=p;i++){
			for(int j=q;j<=p;j++){
				if(a[j]>a[i]){
					swap(a[j],a[i]);
					swap(b[j],b[i]);
					swap(c[j],c[i]);
					swap(z[j],z[i]);
				}
			}
		}
		
		return;
}
void bigswaper(int a[100009],int b[100009],int c[100009],int z[100009],int q,int p){
	for(int i=q;i<=p;i++){
			for(int j=i;j<=p;j++){
				if(a[j]<a[i]){
					swap(a[j],a[i]);
					swap(b[j],b[i]);
					swap(c[j],c[i]);
					swap(z[j],z[i]);
				}
			}
		}
		
		return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	while(m--){
		ans=0;
		
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				z[i]=1;
			}else if(b[i]>a[i]&&b[i]>c[i]){
				z[i]=2;
			}else{
				z[i]=3;
			}
		}
		smallswaper(z,a,b,c,1,n);
		for(i=1;i<=n;i++){
			if(z[i]!=1&&(i-1)>n/2){
				bigswaper(a,b,c,z,1,i-1);
				i--;
				break;
			}
		}
		for(j=1;j<=i;j++){
			ans+=a[i];
			b[i]=0;
			c[i]=0;
		}
		int bb=0,cc=0;
		bigswaper(b,a,c,z,i,n);
		for(j=i;j<=n;j++){
			if(b[j]>c[j]&&bb<=n/2){
				ans+=b[i];
				bb++;
			}else{
				ans+=c[i];
				cc++;
			}
		}
		
		cout<<ans<<endl;
	}
		

}
//Ren5Jie4Di4Ling5%
