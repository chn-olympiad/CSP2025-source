#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int a;
	int b;
	int c;
}club[1000001];//club[i]表示第i个人对1、2、3个部门的满意度 
int n;//新社员人数
int sum=0,sumn=0;//sum为总体的最大满意度，sumn为目前计算的最大满意度 
int pa=0,pb=0,pc=0;//a、b、c三个社团目前已经拥有的人数 
void dfs(int k){//搜索到第k个人 
	if((pa>(n/2))||(pb>(n/2))||(pc>(n/2))){
		return;
	}
	if(k>n){
		if(sumn>sum){
			sum=sumn;
		}
		return;
	}
	for(int i=1;i<=3;i++){//依次搜索三个部门 
		if(i==1){
			sumn+=club[k].a;
			pa++;
			dfs(k+1);
			pa--;
			sumn-=club[k].a;
		}
		if(i==2){
			sumn+=club[k].b;
			pb++;
			dfs(k+1);
			pb--;
			sumn-=club[k].b;
		}
		if(i==3){
			sumn+=club[k].c;
			pc++;
			dfs(k+1);
			pc--;
			sumn-=club[k].c;
		}
	}
}
int main(){
//	freopen("club.in","r",in);
//	freopen("club.out","w",out);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>club[i].a>>club[i].b>>club[i].c;
		}
		dfs(1);
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
