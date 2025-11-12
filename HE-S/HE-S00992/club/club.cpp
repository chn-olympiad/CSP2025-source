#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int num;
int a[1000005],b[1000005],c[1000005];
int z[1000005];
int ak,bk,ck;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int j=1;j<=n;j++){
			if(num<3){
				if(num==2){
					ak=a[j]+b[j];
					bk=a[j]+c[j];
					ck=b[j]+c[j];
					num+=max(ak,max(bk,ck));
				}
				if(num==1){
					num+=max(a[j],max(b[j],c[j]));
				}
				
			}
			num+=a[j]+b[j]+c[j];
			num-=3;
		}
		cout<<num;
		num=0;
	}
	return 0;
} 
