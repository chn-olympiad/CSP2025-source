#include<bits/stdc++.h>
using namespace std;
int a1[100000];
int a2[100000];
int a3[100000];
int maxn;
int ans;
int tp[4]={0};
struct jiegou{
	int shu;
	int xulie;
	int tuan;
	int flagg;
};
bool bml(jiegou x,jiegou y){
	return x.shu>y.shu;
}
jiegou a[100000];
int asu=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ans=0;
		tp[1]=0;
		tp[2]=0;
		tp[3]=0;
		asu=0;
		for(int i=1;i<=n;i++){
			cin>>a[asu].shu;
			a[asu].tuan=1;
			a[asu].xulie=i;
			asu++;
			
			cin>>a[asu].shu;
			a[asu].tuan=2;
			a[asu].xulie=i;
			asu++;
			
			cin>>a[asu].shu;
			a[asu].tuan=3;
			a[asu].xulie=i;
			asu++;
		}
		int y=3*n;
		sort(a,a+y,bml);
		maxn=n/2;
		int jilu[100000];
		int k=0;
		int u=n;
		for(int i=0;i<u;i++){
			int flag=0;
			for(int j=0;j<k;j++){
				if(a[i].xulie==jilu[j]){
					flag=1;
				}
			}
			if(flag==0){
				int o=a[i].tuan;
				if(tp[o]<maxn){
					ans+=a[i].shu;
					tp[o]++;
					jilu[k]=a[i].xulie;
					k++;
				}
				else{
					u++;
				}
			}
			if(flag==1){
				u++;
			}
			
		}
	
		cout<<ans<<endl;
	}
	return 0;
	
} 
