#include<bits/stdc++.h>
using namespace std;
struct ren{
	int z1,z2,z3,zy;
};
ren a[1000001];

int t,n;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].z1>>a[j].z2>>a[j].z3;
		}
		int cnt1=1,cnt2=1,cnt3=1;
		for(int j=1;j<=n;j++){
			int maxn=max(a[j].z1,max(a[j].z2,a[j].z3));
			if(maxn==a[j].z1){
				cnt1++;
				a[j].zy=1;
			}else if(maxn==a[j].z2){
				cnt2++;
				a[j].zy=2;
			}else if(maxn==a[j].z3){
				cnt3++;
				a[j].zy=3;
			}
		}
		if(cnt1>n/2){
			int minn=INT_MAX;
			int min1;
			for(;;){ 
				for(int j=1;j<=n;j++){
					if(a[j].z1<minn&&a[j].zy==1){
						minn=a[j].z1;
						min1=j;
					}
				}
				int m=max(a[min1].z3,a[min1].z2);
				if(m==a[min1].z2&&cnt2+1<=n/2){
					cnt2++;
					a[min1].zy=2;
					cnt1--;
				}else{
					cnt3++;
					a[min1].zy=3;
					cnt1--;
				}
				if(cnt1<=n/2)break;
			}
		}
		if(cnt2>n/2){
			int minn=INT_MAX;
			int min1;
			for(;;){ 
				for(int j=1;j<=n;j++){
					if(a[j].z2<minn&&a[j].zy==2){
						minn=a[j].z2;
						min1=j;
					}
				}
				int m=max(a[min1].z1,a[min1].z3);
				if(m==a[min1].z2&&cnt1+1<=n/2){
					cnt1++;
					a[min1].zy=1;
					cnt2--;
				}else{
					cnt3++;
					a[min1].zy=3;
					cnt2--;
				}
				if(cnt2<=n/2)break;
			}
		}
		if(cnt3>n/2){
			int minn=INT_MAX;
			int min1;
			for(;;){ 
				for(int j=1;j<=n;j++){
					if(a[j].z3<minn&&a[j].zy==3){
						minn=a[j].z2;
						min1=j;
					}
				}
				int m=max(a[min1].z1,a[min1].z2);
				if(m==a[min1].z1&&cnt1+1<=n/2){
					cnt1++;
					a[min1].zy=1;
					cnt3--;
				}else{
					cnt2++;
					a[min1].zy=2;
					cnt3--;
				}
				if(cnt3<=n/2)break;
			}
		}
		int answer=0;
		for(int j=1;j<=n;j++){
			if(a[j].zy==1){
				answer+=a[j].z1;
			}else if(a[j].zy==2){
				answer+=a[j].z2;
			}else if(a[j].zy==3){
				answer+=a[j].z3;
			}
		}
		cout<<answer<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/