#include<bits/stdc++.h>
using namespace std;
long long c[1000000];
long long n,a[1000000][5],b[5],ans;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
	cin>>T;
	while(T--){
		ans=0;
		b[1]=0;
		b[2]=0;
		b[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				b[1]++;
				ans+=a[i][1];
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				b[2]++;
				ans+=a[i][2];
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				b[3]++;
				ans+=a[i][3];
			}
		}
		long long top=0;
		if(b[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
					c[++top]=a[i][1]-max(a[i][2],a[i][3]);
				}
			}
			sort(c+1,c+top+1);
			for(int i=1;i<=b[1]-n/2;i++){
				ans-=c[i];
			}
		}else if(b[2]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
					c[++top]=a[i][2]-max(a[i][1],a[i][3]);
				}
			}
			sort(c+1,c+top+1);
			for(int i=1;i<=b[2]-n/2;i++){
				ans-=c[i];
			}
		}else if(b[3]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
					c[++top]=a[i][3]-max(a[i][1],a[i][2]);
				}
			}
			sort(c+1,c+top+1);
			for(int i=1;i<=b[3]-n/2;i++){
				ans-=c[i];
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
	//return 0;
	//return 0;
	//return 0;
	//return 0;//return 0;//return 0;
	//return 0;
}
