 //GZ-S00328 贵阳市花溪区同为京学附属实验学校 王洪羿

#include<bits/stdc++.h>
using namespace std;
int const N=1e5+1;
int t,n,a[N][4],b[4],sum[5],maxx;	 /*测试数据组数,成员数,各成员对各部门满意度,部门人数,总满意度*/ 
int main(){
	cin>>t;
	for(int abc=0;abc<t;abc++){		/*总数据数abc*/
		cin>>n;		/*每组数据人数*/ 
		for(int i=1;i<=n;i++){		
			for(int j=1;j<=3;j++) cin>>a[i][j];		/*第i个学生对第j个部门的满意度*/ 
		}
		for(int i=1;i<=n;i++){
			maxx=max(a[i][1],a[i][2]);	/*最大满意度*/ 
			maxx=max(maxx,a[i][3]);
			for(int j=1;j<=3;j++){
				if(a[i][j]==maxx&&b[j]<n/2+1){
					b[j]++;		/*满足条件，则该部门人数加1*/ 
					sum[abc]+=maxx;		/*总满意度增加*/ 
				}else{
					sum[abc]+=0;
				}
			}		
		}
	}
	for(int i=0;i<t;i++) cout<<sum[i]<<endl; 
	return 0;
}
