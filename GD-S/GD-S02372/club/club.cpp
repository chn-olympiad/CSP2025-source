#include<bits/stdc++.h>
using namespace std;
// 新成员     总测试数 
int  n   ,       t;
struct node{
//     对1团的满意度	 对2团的满意度     对3团的满意度  
	int 	d1,				d2,				d3;
//    总满意度   		社团总人数  
	int z,			r;
	
};
bool cmp(node x,node y){
	return x.d1>y.d1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	输入总测试数 
	
	cin>>t;
//总组数	
	for(int q=1;q<=t;q++){
		int sum=0;
		node a[100005],d1,d2,d3;
	//		招到人数 
		cin>>n;
	//		限制人数 
		int l=n/2;
	
		for(int i=1;i<=n;i++){
		//		每人对每个社团的满意度 
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			if(n==2)	sum+=max(max(a[i].d1,a[i].d2),a[i].d3);
		} 
		if(n!=2){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=l;i++){
				sum+=a[i].d1;
			}
		}
		cout<<sum;
	}
	
	
	return 0;
}
