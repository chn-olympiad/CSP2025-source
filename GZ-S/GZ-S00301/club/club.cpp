#include<bits/stdc++.h>
using namespace std;
struct dd{
	int a[3]={0};
};
dd p[10000001];
long long max(long long n[3]){//求出每人在三个社团中的最高满意度 
	if(n[0]>=n[1]&&n[0]>=n[2]){
		return n[0];
	}
	if(n[1]>=n[0]&&n[1]>=n[2]){
		return n[1];
	}
	if(n[2]>=n[1]&&n[2]>=n[0]){
		return n[2];
	}
}
long long scd(long long n[3]){//求出满意度为第二高的社团 
	if((n[0]>=n[1]&&n[1]>=n[2])||(n[2]>=n[1]&&n[1]>=n[0])){
		return n[1];
	}
	if((n[1]>=n[0]&&n[0]>=n[2])||(n[2]>=n[0]&&n[0]>=n[1])){
		return n[0];
	}
	if((n[1]>=n[2]&&n[2]>=n[0])||(n[0]>=n[2]&&n[2]>=n[1])){
		return n[2];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t=0;//测试数据量 
	cin>>t;
	long long n=0;//人数 

	long long cy=0;//判断一个社团里分配的人数 
	
	long long m[3]={0};//暂时存储一个人的满意度 
	long long first=0;//社团1人数 
	long long second=0;//社团2人数 
	long long third=0;//社团3人数 
	long long z=0;//总的最高满意度 

	for(int i=0;i<t;i++){
		cin>>n;
		long long b[n]={0};//记录每人的最高满意度
		long long c[n]={0};//记录一个人第二高满意度 
		long long v[n]={0};
		int u[n]={0};
		for(int j=0;j<n;j++){
			for(int o=0;o<3;o++){
				cin>>p[j].a[o];
			}
		}
		for(int j=0;j<n;j++){
			for(int o=0;o<3;o++){
				m[o]=p[j].a[o];
				b[j]=max(m);
				c[j]=scd(m);
			}
		}
		int r=0;
		for(int j=0;j<n;j++){
			if(b[j]==p[j].a[0]){
				v[r]=p[j].a[0];
				u[r]=j;
				r++;
			}
		if(j==n){
		for(int t=0;t<n;t++){
		for(int o=t;o<n;o++){
				if(v[t]<v[o]){
					swap(p[u[r]],p[u[r+1]]);
				}
			}
			}
			
		}
		}
	}
}
