#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
struct xue{
	int d1,d2,d3;
	int d[4]={0};
	int xuan=-1;
}po[100001];
bool cmp1(xue a,xue b){
	return a.d1>b.d1;
}
bool cmp2(xue a,xue b){
	return a.d2>b.d2;
}
bool cmp3(xue a,xue b){
	return a.d3>b.d3;
}

int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	while(n--){
		xue po[10001]={};
		sum=0;
		int d11=0,d22=0,d33=0;
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>po[i].d1>>po[i].d2>>po[i].d3;
			po[i].d[1]=po[i].d1;
			po[i].d[2]=po[i].d2;
			po[i].d[3]=po[i].d3;
		}
//		po[m+1].d1=0;
//		po[m+1].d2=0;
//		po[m+1].d3=0;
//		for(int i=0;i<3;i++){
//			po[m+1].d[i]=0;
//		}
		sort(po+1,po+1+m,cmp1);
		for(int i=1;i<=m;i++){
			if(po[i].xuan==-1){
				sum+=po[i].d1;
			//	cout<<sum<<' ';
				po[i].xuan=1;
				d11++;
				if(d11==m/2)break;
				}
				
			}
		sort(po+1,po+1+m,cmp2);
		for(int i=1;i<=m;i++){
			if(po[i].xuan==-1){
				sum+=po[i].d2;
				po[i].xuan=2;
				d22++;
			//	cout<<sum<<' ';
				if(d22==m/2)break;}
			else{
				if(po[i].d2+po[i+1].d1>po[i].d1+po[i+1].d2){
					po[i].xuan=2;
					sum=sum-po[i].d1+po[i].d2+po[i+1].d1;
					d11--;
					d22++;
					//cout<<sum<<' ';
					if(d22==m/2)break;
				}
			}
			
		}
		sort(po+1,po+1+m,cmp3);
		for(int i=1;i<=m;i++){
				if(po[i].d3+po[i+1].d[po[i+1].xuan]>po[i+1].d3+po[i].d[po[i].xuan]){
					//cout<<sum<<' '<<po[i].d3<<' '<<po[i].d[po[i].xuan]<<' '<<po[i].xuan<<' ';
					sum=sum-po[i].d[po[i].xuan]+po[i].d3+po[i+1].d[po[i+1].xuan];
					d33++;
					po[i].xuan=3;
					
				//	cout<<sum<<endl;
					if(d33==m/2)break;
				}
			
		}

		cout<<sum<<endl;
	}
	return 0;
}

