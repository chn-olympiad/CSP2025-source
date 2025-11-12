#include<bits/stdc++.h>
using namespace std;
int tt;
int n;
int ans=0;
int a[100005][5];
int aa[100005][5];//下标 
struct f{
	int x,y,qll;
}dd[100005];
int aaa,bbb,ccc;
bool cmp(f x,f y){
	return x.x<y.x;
}
int zhy(){
	ans=0;
	aaa=0;
	bbb=0;
	ccc=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int maxn=0,p=1;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]>maxn){
				maxn=a[i][j];
				p=j;
			}
		}
		if(p==1){
			aaa+=1;
			aa[aaa][1]=i;
		}else if(p==2){
			bbb+=1;
			aa[bbb][2]=i;
		}else{
			ccc+=1;
			aa[ccc][3]=i;
		}
	}
	for(int j=1;j<=3;j++){
		for(int i=1;i<=100000;i++){
			dd[i].x=0;
			dd[i].y=0;
			dd[i].qll=0;
		}
		if(j==1){
			if(aaa>n/2){
				int xs=0;
				for(int i=1;i<=aaa;i++){
					xs++;
					if(a[aa[i][1]][j]-a[aa[i][1]][2]>a[aa[i][1]][j]-a[aa[i][1]][3]){
						dd[xs].qll=3;
					}else{
						dd[xs].qll=2;
					}
					dd[xs].x=min(a[aa[i][1]][j]-a[aa[i][1]][2],a[aa[i][1]][j]-a[aa[i][1]][3]);
					dd[xs].y=aa[i][1];
				}
				sort(dd+1,dd+xs+1,cmp);
				for(int i=1;i<=aaa-n/2;i++){
					if(dd[i].qll==2){
						bbb+=1;
						aa[bbb][2]=dd[i].y;
					}else{
						ccc+=1;
						aa[ccc][3]=dd[i].y;
					}
				}
			}
			for(int i=aaa-n/2+1;i<=aaa;i++){
				ans+=a[aa[i][1]][1];
			}
		}else if(j==2){
			if(bbb>n/2){
				int xs=0;
				for(int i=1;i<=bbb;i++){
					xs++;
					dd[xs].qll=3;
					dd[xs].x=a[aa[i][2]][j]-a[aa[i][2]][3];
					dd[xs].y=aa[i][2];
				}
				sort(dd+1,dd+xs+1,cmp);
				for(int i=1;i<=bbb-n/2;i++){
					ccc+=1;
					aa[ccc][3]=dd[i].y;
				}
			}for(int i=bbb-n/2+1;i<=bbb;i++){
				ans+=a[aa[i][2]][2];
			}
		}else{
			for(int i=1;i<=ccc;i++){
				ans+=a[aa[i][3]][3];
			}
		}
	}
}
int main(){
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tt;
	while(tt--){
		zhy();
		cout<<ans<<"\n";
	}
	return 0;
}
//int溢出
//freopen去注释 
