#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5e4+5;

//记录数据 
int w[MAX_N][4];

//add
struct mem_hh{
	int w1,w2,w3;
	int w1_w2=abs(w1-w2),w2_w3=abs(w2-w3),w1_w3=abs(w1-w3);
}mem[MAX_N];

int club_min[4][MAX_N];
int club_num[4];
int club_max[4];
int max_n;
int other=0;
bool vis[MAX_N];

void add(int member_Num,int mem_w,int mem_club){
	if(club_num[mem_club]>=max_n){
		int ans=200000,p=0;
		for(int i=1;i<=club_num[mem_club];i++){
			if(ans>club_min[mem_club][i] && vis[i]==0){
				ans=club_min[mem_club][i];
				p=i;
			}
			if(ans>min(mem[member_Num].w1_w2,min(mem[member_Num].w1_w3,mem[member_Num].w2_w3))){
				vis[member_Num]=1;
				club_max[mem_club]-=min(mem[member_Num].w1_w2,min(mem[member_Num].w1_w3,mem[member_Num].w2_w3));
			}
			else {
				vis[p]=1;
				club_max[mem_club]-=ans;
			}
			
		}
	}//比较当前人和备选人中最小的值，减去输的人的备选值 
	//人数冲突 (没调成功，现在这个程序正在以一种诡异的方式运行？？？)
	
	club_max[mem_club]+=mem_w;//满意度增加 
	club_num[mem_club]++;//部门人数增加 
	club_min[member_Num][club_num[mem_club]]=min(mem[member_Num].w1_w2,min(mem[member_Num].w1_w3,mem[member_Num].w2_w3));//每个人的备选方案 /备选值 
	//人数不冲突，加入的对应的部门
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		max_n=n/2;
		for(int i=1;i<=n;i++){
			cin>>w[i][1]>>w[i][2]>>w[i][3];
			mem[i].w1=w[i][1];mem[i].w2=w[i][2];mem[i].w3=w[i][3];
			if(w[i][1]>=w[i][2]&&w[i][1]>=w[i][3])add(1,w[i][1],1);
			else if(w[i][2]>=w[i][1]&&w[i][2]>=w[i][3])add(1,w[i][2],2);
			else if(w[i][3]>=w[i][2]&&w[i][3]>=w[i][1])add(1,w[i][3],3);
		}
		cout<<club_max[1]+club_max[2]+club_max[3]<<endl;
	}
	
	return 0;
}
//呵，真是好久没练了 
//啊~   D： 
//18:09 XD 
