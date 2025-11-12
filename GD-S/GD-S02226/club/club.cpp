#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[4],m1,m2;
struct xs{
	int a[4];
	int mh;
	int cz;
};xs cy[100005];
bool cmp(xs x,xs y){
	if(x.mh==m2&&y.mh!=m2){
		return true;
	}
	if(y.mh==m2&&x.mh!=m2){
		return false;
	}
	return x.cz>y.cz;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>cy[i].a[j];
			}
			if(cy[i].a[1]>=cy[i].a[2]){
				if(cy[i].a[1]>=cy[i].a[3]){
					cy[i].mh=1;
					cnt[1]++;
					if(cy[i].a[2]>cy[i].a[3]){
						cy[i].cz=cy[i].a[1]-cy[i].a[2];
					}
					else{
						cy[i].cz=cy[i].a[1]-cy[i].a[3];
					}
				}
				else{
					cy[i].mh=3;
					cnt[3]++;
					cy[i].cz=cy[i].a[3]-cy[i].a[1];
				}
			}
			else{
				if(cy[i].a[2]>=cy[i].a[3]){
					cy[i].mh=2;
					cnt[2]++;
					if(cy[i].a[1]>cy[i].a[3]){
						cy[i].cz=cy[i].a[2]-cy[i].a[1];
					}
					else{
						cy[i].cz=cy[i].a[2]-cy[i].a[3];
					}
				}
				else{
					cnt[3]++;
					cy[i].mh=3;
					cy[i].cz=cy[i].a[3]-cy[i].a[2];
				}
			}
		}
		m1=cnt[1];
		m2=1;
		for(int i=2;i<=3;i++){
			if(cnt[i]>m1){
				m1=cnt[i];
				m2=i;
			}
		}
		int sum=0;
		if(m1<=n/2){
			for(int i=1;i<=n;i++){
				sum+=cy[i].a[cy[i].mh];
			}
			cout<<sum<<endl;
			continue;
		}
		sort(cy+1,cy+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(i<=n/2){
				sum+=cy[i].a[cy[i].mh];
			}
			else{
				if(cy[i].mh==m2){
					sum+=cy[i].a[m2]-cy[i].cz;
				}
				else{
					sum+=cy[i].a[cy[i].mh];
				}
			}
		}
		cout<<sum<<endl;	
	}
	return 0;
}
