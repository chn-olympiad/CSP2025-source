#include<bits/stdc++.h>
#define L 100010
using namespace std;
bool cmpint(int x,int y){
	return x>y;
}
int T;
int n;
int ans[3];
struct hby{
	int x,ord;
};
bool cmphby(hby x,hby y){
	return x.x>y.x;
}
struct stu{
	int a[3];
	hby sod[3];
	bool used;
	void find(){
		for(int i=0;i<3;i++){
			sod[i].x=a[i];
			sod[i].ord=i;
		}
		sort(sod,sod+3,cmphby);
	}
}l[L];
int t[3][3][L/2],cmd[3][3];
int sum[3],ssum;
int pers[3];
void son(){
	memset(l,0,sizeof(l));
	memset(t,0,sizeof(t));
	memset(cmd,0,sizeof(cmd));
	memset(sum,0,sizeof(sum));
	memset(pers,0,sizeof(pers));
	ssum=0;
	cin>>n;
	for(int i=0;i<n;i++){ 
		for(int j=0;j<3;j++){
			cin>>l[i].a[j];
			l[i].used=false;
		}
		l[i].find();
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			int temp=l[i].sod[j].ord;
			t[temp][j][cmd[temp][j]++]=l[i].a[temp];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			sort(t[i][j],t[i][j]+cmd[i][j],cmpint);
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				if(pers[i]<n/2){
					sum[i]+=t[i][k][j];
					pers[i]++;
					break;
				}
			}
		}
	}
	for(int i=0;i<3;i++){
		ssum+=sum[i];
	}
	cout<<ssum<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int i=0;i<T;i++){
		son();
	}
	return 0;
}
