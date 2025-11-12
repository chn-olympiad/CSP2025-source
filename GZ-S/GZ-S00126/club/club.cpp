//GZ-S00126 贵阳市南明区华麟学校 娄芷淇 
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],cnt,d[5],maxa,maxw,maxw1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			maxa=0,maxw=0;
			if(a[j]>maxa){
				maxa=a[j];
				maxw=1;
			}
			if(b[j]>maxa){
				maxa=b[j];
				maxw=2;
			}
			if(c[j]>maxa){
				maxa=c[j];
				maxw=3;
			}
			maxw1=0;
			if(d[maxw]+1>n/2){
				if(maxw==1){
					if(b[j]>maxa){
						maxa=b[j];
						maxw1=2;
					}
					if(c[j]>maxa){
						maxa=c[j];
						maxw1=3;
					}
				}
				if(maxw==2){
					if(a[j]>maxa){
						maxa=a[j];
						maxw1=1;
					}
					if(c[j]>maxa){
						maxa=c[j];
						maxw1=3;
					}
				}
				if(maxw==3){
					if(b[j]>maxa){
						maxa=b[j];
						maxw1=2;
					}
					if(a[j]>maxa){
						maxa=a[j];
						maxw1=1;
					}
				}
				d[maxw1]+=1;
				cnt+=maxa;
			}
			else{
				d[maxw]+=1;
				cnt+=maxa;
			}
		}
		cout<<cnt<<endl;
		maxw1=0,maxw=0,maxa=0,cnt=0;
	}
	return 0;
}
