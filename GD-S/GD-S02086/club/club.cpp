#include<bits/stdc++.h>
using namespace std;
int xy[1000000][1000000],a[1000000],b[1000000],c[1000000],n,t,shu,sum,maxa,maxb,maxc,aj,bj,cj;
int plan(int a,int b,int c){
	int max =a,shu=0;
	if(max<b)shu=1;
	if(max<c)shu=2;
	return shu;
}
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i =0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>xy[i][j];
			}
		}
	for(int i =0;i<n;i++){
		a[i]=0;
		b[i]=0;
		c[i]=0;
	}
	aj=0,bj=0,cj=0;
	for(int i =0;i<n;i++){
			shu = plan(xy[i][0],xy[i][1],xy[i][2]);
			if(shu==0){
				a[i]=xy[i][0];
			}
			if(shu==1){
				b[i]=xy[i][1];
			}
			if(shu==2){
				c[i]=xy[i][2];
			}
	}
	sum=0;
	for(int i =0;i<n;i++){
	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	sort(c,c+n,cmp);
	if(aj<2){
		sum+=a[i];
		aj++;
	}
	if(bj<2){
		sum+=b[i];
		bj++;
	}
	if(cj<2){
		sum+=c[i];
		cj++;
	}
	//cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<endl;
	}
	cout<<sum<<" ";
}
return 0;
}
