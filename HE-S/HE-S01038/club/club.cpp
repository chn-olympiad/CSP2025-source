#include<bits/stdc++.h>
using namespace std;
int a[100010][10],b[100010][10];
struct Z{
	int ma,n;
} z[100010];
int ba[5];//选择第几个部门的人数
void win(int a,int b,int c,int i){
	if(b==z[i].ma){
			z[i].n=2,ba[2]++;
	} 
	else if(a==z[i].ma){
			z[i].n=1,ba[1]++;
	} 
	else if(c==z[i].ma){
			z[i].n=3,ba[3]++;
	} 
}
bool cmp1 (Z z1,Z z2){
	return z1.ma>z2.ma;
}
bool cmp2 (Z z1 ,Z z2){
	if(z1.n!=z2.n) z1.n<z2.n;
	return z1.ma>z2.ma;
}
bool cmp3 (Z z1 ,Z z2){
	if(z1.n!=z2.n) z1.n>z2.n;
	return z1.ma>z2.ma;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		int n;cin>>n;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			z[i].ma=max(max(a[i][1],a[i][3]),a[i][2]);
			win(a[i][1],a[i][2],a[i][3],i);
		}
		if(a[1][2]==0&&a[1][3]==0){
			sort(z+1,z+n+1,cmp1);
			int tot=0;
			for(int i=1;i<=n/2;i++){
				tot+=z[i].ma;
			}
			cout<<tot;
			return 0;
		}
		else if(a[1][3]==0){
			int tot=0;
			if(ba[1]>n/2){
			sort(z+1,z+n+1,cmp2);
				
				for(int i=1;i<=n/2;i++){
					tot+=z[i].ma;
				}
				for(int i=n/2;i<=n;i++){
					tot+=a[z[i].n][2];
				}
			}else{
				sort(z+1,z+n+1,cmp3);
				
				for(int i=1;i<=n/2;i++){
					tot+=z[i].ma;
				}
				for(int i=n/2;i<=n;i++){
					tot+=a[z[i].n][1];
				}
			}
			cout<<tot;
			return 0;
		}
		else{
		
			if(ba[1]>n/2||ba[2]>n/2||ba[3]>n/2){
//				wo(ba[1],ba[2],ba[3]);
			}else{
				for(int i=1;i<=n;i++){
					cnt+=z[i].ma;
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}
