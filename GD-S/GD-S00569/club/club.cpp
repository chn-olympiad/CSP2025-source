#include<bits/stdc++.h>
using namespace std;
int t,n,an,bn,cn,sum,abc[100010][3];
int am[50010],bm[50010],cm[50010];
int find(int x,int y){
	if(abc[x][0]==y) return 0;
	if(abc[x][1]==y) return 1;
	if(abc[x][2]==y) return 2;
}
int next(int x,int y){
	if(abc[x][y]==max({abc[x][0],abc[x][1],abc[x][2]})){
		if(y==0) return max(abc[x][1],abc[x][2]);
		if(y==1) return max(abc[x][0],abc[x][2]);
		if(y==2) return max(abc[x][1],abc[x][0]);
	}else{
		if(y==0) return min(abc[x][1],abc[x][2]);
		if(y==1) return min(abc[x][0],abc[x][2]);
		if(y==2) return min(abc[x][1],abc[x][0]);
	}
}
void full(int i){
	cout<<i<<"  "<<endl;
	int m=0,mm=0;
	pair <int,int> p;
	if(i==0){
		for(int j=0;j<=n/2;j++){
			if(abc[am[j]][0]<=m){
			m=abc[am[j]][0];
			p.first=am[j];
			p.second=0;	
			mm=j;
			}
		}
		sum-=am[mm];
		for(int j=mm;j<=n/2;j++){
			am[j]=am[j+1];
		}
		an--;
	}
	else if(i==1){
		for(int j=0;j<=n/2;j++){
			if(abc[bm[j]][1]<=m){
			m=abc[bm[j]][1];
			p.first=bm[j];
			p.second=1;	
			mm=j;
			}
		}
		sum-=bm[mm];
		for(int j=mm;j<=n/2;j++){
			am[j]=am[j+1];
		}
		bn--;
	}
	else if(i==2){
		for(int j=0;j<=n/2;j++){
			if(abc[cm[j]][2]<=m){
			m=abc[cm[j]][2];
			p.first=cm[j];
			p.second=2;	
			mm=j;
			}	
		}
		sum-=cm[mm];
		for(int j=mm;j<=n/2;j++){
			bm[j]=am[j+1];
		}
		cn--;
	}
	int nx=next(p.first,p.second),bl=find(p.first,nx);
	if(bl==0){
		am[an++]=p.first;
		sum+=nx;
		if(an>n/2) full(0);
	}else if(bl==1){
		bm[bn++]=p.first;
		sum+=nx;
		if(bn>n/2) full(1);
	}else if(bl==2){
		cm[cn++]=p.first;
		sum+=nx;
		if(cn>n/2) full(2);
	}

}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;

	for(int p=0;p<t;p++){
		cin>>n;
		for(int i=0;i<n;i++){
		cin>>abc[i][0]>>abc[i][1]>>abc[i][2];
		int mm=max({abc[i][0],abc[i][1],abc[i][2]});
//		cout<<"0    ";
		if(mm==abc[i][0]) {
			if(an<n/2){
				sum+=mm;
				am[an++]=i;
			}else {
				sum+=mm;
				am[an++]=i;
				full(0);
			}
		}else if(mm==abc[i][1]){
			if(bn<n/2){
				sum+=mm;
				bm[bn++]=i;
			}else {
				sum+=mm;
				bm[bn++]=i;
				full(1);
			}
		}else if(mm==abc[i][2]){
			if(cn<n/2){
				sum+=mm;
				cm[cn++]=i;
			}else {
				sum+=mm;
				cm[cn++]=i;
				full(2);
			}
		}
		cout<<"1    ";
		
	}
	cout<<sum<<endl;
		sum=0;
	}
	return 0;
} 
//Ren5Jie4Di4Ling5%
//屎山代码这一块
//写完了运行结果一堆错误这一块
//写了四个小时一分没拿这一块
//明年去J级了不来S级玩了拜拜
//:) 
