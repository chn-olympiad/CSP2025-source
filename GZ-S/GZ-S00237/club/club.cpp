//GZ-S00237 贵阳市为明高级中学 李竹风 
#include<bits/stdc++.h>
using namespace std;
long long a[100005][4];
long long s[4][3];
long long mn[100005]; 
long long cha[100005]; 
long long nm[100005];
int n;
//b为第几部门 
void Check(int b){ 
	//找该部门兴趣一二变化最小 
	int minn=2e9,x=-1;
	for(int i=1;i<=n;i++){
		if(minn>cha[i]){
			minn=cha[i];
			x=i;//第几人 
		}
	}
	s[b][1]-=a[x][b];
	s[b][2]--;
	//找此人第二大 
	int maxn=-2e9,c=-1;
	for(int i=1;i<=3;i++){
		if(i==nm[x])continue;
		if(maxn<a[x][i]){
			maxn=a[x][i];
			c=i;
		}	
	}
	s[c][1]+=maxn;
	s[c][2]++;
	if(s[b][2]>n/2){
		Check(b);
	}
	else return;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			long long num;
			cin>>num;
			a[i][j]=num;
		}
	}
	//每人最小值de坐标 
	for(int i=1;i<=n;i++){
		int d=2e9,e=-1;
		for(int j=1;j<=3;j++){
			if(a[i][j]<d){
				d=a[i][j];
				e=j;
			}
		}
		mn[i]=e;
	}
	//每人最大值的坐标 
	for(int i=1;i<=n;i++){
		int f=-2e9,g=-1;
		for(int j=1;j<=3;j++){
			if(a[i][j]>f){
				f=a[i][j];
				g=j;
			}
		}
		nm[i]=g;
	} 
	//一二差值
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(j==mn[i]){
				continue;
			}
			cha[i]=int(abs(cha[i]-a[i][j]));
		}
	}
	for(int i=1;i<=n;i++){
		int xb=-1,m=-2e9;
		for(int j=1;j<=3;j++){
			if(a[i][j]>m){
				xb=j;
				m=a[i][j];
			}
		}
		s[xb][1]+=a[i][xb];
		s[xb][2]++;
	}
	//每个检查 
	for(int k=1;k<=3;k++){
		for(int i=1;i<=3;i++){
			if(s[i][2]>(n/2)){
				Check(i); 
			}
		}
	}
	int sum=s[1][1]+s[2][1]+s[3][1];
	cout<<sum<<endl;
	//初始化 
	for(int i=1;i<=3;i++){
		for(int j=1;j<=2;j++){
			s[i][j]=0;
		}
	}
	}
//	fclose(stdin);
//	fclose(stdout); 
	return 0;
}
