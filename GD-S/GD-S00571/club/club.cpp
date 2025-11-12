#include<bits/stdc++.h>
using namespace std;
int a[100005][3]={0},b[100005][2]={0},c[100005]={0};
int cz(int q){
	int mq=0;
	for(int i=0;i<3;i++){
		mq=max(a[q][i],mq);
	}
	return mq;
}
void xx(int x){
	int ma=0;
	for(int i=1;i<3;i++){
		if(a[x][i]>a[x][ma]){
			ma=i;
		}
	}
	b[x][0]=a[x][ma];
	b[x][1]=ma;
	a[x][ma]=0;
	c[x]=b[x][0]-cz(x);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int cou=0,n,bm[3]={0},cis=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			xx(i);
		}
		sort(c,c+n);
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(j==b[i][1]){
					bm[j]++;
					cou+=b[i][0];
					continue;
				}
			}
		}
		for(int j=0;j<3;j++){
				if(bm[j]-n/2>0){
					cis+=bm[j]-n/2;
					for(int i=0;i<cis;i++){
						cou-=c[i];
					}
				}
			}
		cout<<cou<<endl;
		a[100005][3]={0};
		b[100005][2]={0};
		c[100005]={0};
	}
	return 0;
}
