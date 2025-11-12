#include<bits/stdc++.h>
#include<iostream>

freopen("club.in","r",stdcin);
freopen("club.out","w",stdcout);//我草我忘记怎么写freopen了，这下零蛋了 

using namespace std;

struct st{
	int n,a;
};//用于排序

bool cmp(st a,st b){
	return a.a>b.a;
}//用于排序 

int best(int a1,int a2,int a3){
	if(a1>=a2&&a1>=a3){
		return 1;
	}
	else if(a2>=a1&&a2>=a3){
		return 2;
	}
	else if(a3>=a1&&a3>=a2){
		return 3;
	}
}//对于单个学生的3个a值取最大值 
/*
st sorts(st a[],int l,int r){
	for(int i=r;i>=0;i++){
		for(int j=i;j>=0;j++){
			if(cmp(a[j-1],a[j])){
				st temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
	return a;
}
*/
st mina(st a[],int pop){
	int mini=100000;
	st minst;
	for(int i=0;i<pop;i++){
		if(mini>a[i].a){
			minst=a[i];
			mini=a[i].a;
		}
	}
	return minst;
}

int minn(st a[],int pop){
	int mini=100000,minb;
	for(int i=0;i<pop;i++){
		if(mini>a[i].a){
			minb=i;
			mini=a[i].a;
		}
	}
	return minb;
}

int main(){
	int t;//测试点数量 
	cin>>t;
	int a_total[t][20000][3];
	int n_total[t];//人数
	for(int j=0;j<t;j++){
		cin>>n_total[j];
		for(int i=0;i<n_total[j];i++){
			cin>>a_total[j][i][0]>>a_total[j][i][1]>>a_total[j][i][2];
		}
	}
	long long ans[t];//答案存在这里面 
	for(int j=0;j<t;j++){
		
		int n=n_total[j];
		
		bool mark2=0,mark3=0;
		
		st a1[n],a2[n],a3[n];//分别是三个部门的满意度 
		int a[n][3];
		
		for(int i=0;i<n;i++){
			a[i][0]=a_total[j][i][0];
			a[i][1]=a_total[j][i][1];
			a[i][2]=a_total[j][i][2];
			/*
			if(a[i][1]!=0){
				mark2=1;
			}
			if(a[i][2]!=0){
				mark3=1;
			}
			
			a2[i].a=a[i][1],a2[i].n=i;
			a3[i].a=a[i][2],a3[i].n=i;
			*/
		}
		
		int pop1=0,pop2=0,pop3=0;
		
		for(int i=0;i<n;i++){
			switch(best(a[i][0],a[i][1],a[i][2])){
				case 1:{
					if(pop1<n/2){
						a1[pop1].a=a[i][0],a1[pop1].n=i;
						pop1+=1;
						ans[j]+=a[i][0];
					}
					else{
						if(a[i][0]>=mina(a1,pop1).a){
							int c_st=minn(a1,pop1);
							a1[minn(a1,pop1)].a=a[i][0];a1[minn(a1,pop1)].n=i;
							ans[j]+=a[i][0];
							if(a[c_st][1]>a[c_st][2]){
								a2[pop2].a=a[c_st][0],a2[pop2].n=c_st;
								pop2+=1;
							}
							else{
								a3[pop3].a=a[c_st][0],a3[pop3].n=c_st;
								pop3+=1;
							}
						}
						if(a[i][1]>a[i][2]){
							a2[pop2].a=a[i][0],a2[pop2].n=i;
							pop2+=1;
						}
						else{
							a3[pop3].a=a[i][0],a3[pop3].n=i;
							pop3+=1;
						}
					}
					break;
				}
				case 2:{
					if(pop2<n/2){
						a2[pop2].a=a[i][1],a2[pop2].n=i;
						pop2+=1;
						ans[j]+=a[i][1];
					}
					else{
						if(a[i][1]>=mina(a2,pop2).a){
							int c_st=minn(a2,pop2);
							a2[minn(a2,pop2)].a=a[i][0],a2[minn(a2,pop2)].n=i;
							ans[j]+=a[i][1];
							if(a[c_st][0]>a[c_st][2]){
								a1[pop1].a=a[c_st][0],a1[pop1].n=c_st;
								pop2+=1;
							}
							else{
								a3[pop3].a=a[c_st][0],a3[pop3].n=c_st;
								pop3+=1;
							}
						}
						if(a[i][0]>a[i][2]){
							a1[pop1].a=a[i][0],a1[pop1].n=i;
							pop2+=1;
						}
						else{
							a3[pop3].a=a[i][0],a3[pop3].n=i;
							pop3+=1;
						}
					}
					break;
				}
				case 3:{
					if(pop3<n/2){
						a3[pop3].a=a[i][2],a3[pop3].n=i;
						pop3+=1;
						ans[j]+=a[i][2];
					}
					else{
						if(a[i][2]>=mina(a3,pop3).a){
							int c_st=minn(a3,pop3);
							a3[minn(a3,pop3)].a=a[i][0],a3[minn(a3,pop3)].n=i;
							ans[j]+=a[i][0];
							if(a[c_st][0]>a[c_st][1]){
								a1[pop1].a=a[c_st][0],a1[pop1].n=c_st;
								pop2+=1;
							}
							else{
								a2[pop2].a=a[c_st][1],a2[pop3].n=c_st;
								pop2+=1;
							}
						}
						if(a[i][0]>a[i][1]){
							a1[pop1].a=a[i][0],a1[pop1].n=i;
							pop2+=1;
						}
						else{
							a2[pop2].a=a[i][1],a2[pop3].n=i;
							pop2+=1;
						}
					}
					break;
				}
			}
		}//完全不是人的代码，大概就是先判定满没满，没满就直接加进去，同时记录加了谁，如果满了就看看里面有没有比他小的，如果有，把最小的替换掉，然后令最小的另找一个地方放（使得答案最大），如果没有，那就让其另找一个地方放 
	}
	for(int i=0;i<t;i++){
		cout<<ans[i];
	}
	return 0;
}
