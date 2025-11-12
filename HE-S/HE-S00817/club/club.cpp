#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	struct stu{
		public:
			//储存该成员对3个部门的喜爱度 
			int part[3]={0};
			//stupart储存该成员所在的部门序号，4为未加入 
			int stupart=4;
			//Max函数返回喜爱度最大的部门 
			int Max(){
				int max=0;
				//擂台法找最大，max为最大值下标 
				for(int i=0;i<3;i++){
					for(int j=0;j<3;j++){
						if(part[i]>part[max]) max=i;
					}
				}
				return(max);
			}
	};
	int t=0;
	cin>>t;  //输入测试组数
	int out[t]; //储存将要输出的非负整数
	
	/*
	因为是多测试案例的题，所以在一次整体输入中会有好几个分区，
	所以在测试组数的循环中直接处理完答案，储存到out中，到最后集体输出 。 
	*/ 
	for(int i=0;i<t;i++){
		//输入学生个数 
		int stunum;
		cin>>stunum;
		stu student[stunum];  //定义学生的集体数组 
		for(int j=0;j<stunum;j++){
			cin>>student[j].part[0]>>student[j].part[1]>>student[j].part[2];  //输入学生的满意度 (编译无报错，未复盘) 
		}
		int part1=0,part2=0,part3=0;  //3个部门总人数，过程中不做改变，在最后通过相对应的vector的size赋值 
		//判断每个成员最大喜爱度的部门并加进去。 
		for(int j=0;j<stunum;j++){
			if(student[j].Max()==0) {student[j].stupart=1; part1++;}
			if(student[j].Max()==1) {student[j].stupart=2; part2++;}
			if(student[j].Max()==2) {student[j].stupart=3; part3++;}
		}
		int halfstu=stunum/2;  //一半学生数量 
		//最终判断是否符合题目要求 
		bool isok=false;
		
		
		
		while(!isok){
			if(part1<=halfstu && part2<=halfstu && part3<=halfstu){
			int HappyC=0;
			for(int j=0;j<stunum;j++){
				HappyC+=student[i].part[student[i].stupart-1]; //在原基础上加该学生对所在部门的满意度 
			}
			out[i]=HappyC;
			isok=true;  //本测试样例结束 
			}
		
			
			if(part1>halfstu){
				int morestu=part1-halfstu;  //至少需要挪走几个学生才可以满足要求 
				int Happy2[part1][2],Happy3[part1][2];  //该部门中所有成员对其他部门的满意值 ,其中二维0项为该学生下标，1项为满意度 
				//相当于问卷调查，填写 
				for(int j=0;j<part1;j++){
					Happy2[j][1]=student[j].part[1];
					Happy2[j][0]=j;
					Happy3[j][1]=student[j].part[2];   
					Happy2[j][0]=j;
				}
				int px2[part1][2],px3[part1][2]; //排序过后的对其他学院满意度调查 
				int used2=0,used3=0;  //已经用到的数组下标 
				int max2=0,max3=0; //最大值的下标 
				for(int j=0;j<part1;j++){
					for(int k=0;k<part1;k++){
						if(Happy2[k][1]>Happy2[max2][1]){
							max2=k;
						}
					}
					px2[used2][1]=Happy2[max2][1]; //搬到排序数组 
					px2[used2][0]=Happy2[max2][0];
					Happy2[max2][1]=-1; //更改已将排过的满意度为-1，可以保证比任何一个都小 
					//对3排序 
					for(int k=0;k<part1;k++){
						if(Happy3[k][1]>Happy3[max3][1]){
							max3=k;
						}
					}
					px3[used3][1]=Happy3[max3][1]; //搬到排序数组 
					px3[used3][0]=Happy3[max3][0];
					Happy3[max3][1]=-1; //更改已将排过的满意度为-1，可以保证比任何一个都小 
				}
				int golist[morestu][3]; //储存将要转部的学生，二维项0为学生下标，1为满意度 ，2要去的部 
				int last=morestu; //储存还剩几个
			
				while(last!=0){
					//判断在另一个备选名单中的自己的满意度是否大于这个名单中的，如果是的话就把自己删掉。 
					for(int j=0;j<used3;j++) if(px2[morestu-last][0]==px3[j][0] && px3[j][1]>px2[morestu-last][1]) px2[morestu-last][1]=-1;
					for(int j=0;j<used2;j++) if(px3[morestu-last][0]==px2[j][0] && px2[j][1]>px3[morestu-last][1]) px3[morestu-last][1]=-1;
					if(px2[morestu-last][1]>px3[morestu-last][1] && part2+1<=halfstu){
						golist[morestu-last][0]=px2[morestu-last][0];
						golist[morestu-last][1]=px2[morestu-last][1];
						golist[morestu-last][2]=2;
						part2++;
						part1--;
					}
					else if(px3[morestu-last][1]>px2[morestu-last][1] && part3+1<=halfstu){
						golist[morestu-last][0]=px3[morestu-last][0];
						golist[morestu-last][1]=px3[morestu-last][1];
						golist[morestu-last][2]=3;
						part3++;
						part1--;
					}
					last--; 
				}
				for(int j=0;j<morestu;j++){
					student[golist[j][0]].stupart=golist[j][2];
				} 
			}
			else if(part2>halfstu){
				int morestu=part2-halfstu;  //至少需要挪走几个学生才可以满足要求 
				int Happy1[part1][2],Happy3[part1][2];  //该部门中所有成员对其他部门的满意值 ,其中二维0项为该学生下标，1项为满意度 
				//相当于问卷调查，填写 
				for(int j=0;j<part1;j++){
					Happy1[j][1]=student[j].part[1];
					Happy1[j][0]=j;
					Happy3[j][1]=student[j].part[3];   
					Happy3[j][0]=j;
				}
				int px1[part2][2],px3[part2][2]; //排序过后的对其他学院满意度调查 
				int used1=0,used3=0;  //已经用到的数组下标 
				int max1=0,max3=0; //最大值的下标 
				for(int j=0;j<part2;j++){
					for(int k=0;k<part2;k++){
						if(Happy1[k][1]>Happy1[max1][1]){
							max1=k;
						}
					}
					px1[used1][1]=Happy1[max1][1]; //搬到排序数组 
					px1[used1][0]=Happy1[max1][0];
					Happy1[max1][1]=-1; //更改已将排过的满意度为-1，可以保证比任何一个都小 
					//对3排序 
					for(int k=0;k<part2;k++){
						if(Happy3[k][1]>Happy3[max3][1]){
							max3=k;
						}
					}
					px3[used3][1]=Happy3[max3][1]; //搬到排序数组 
					px3[used3][0]=Happy3[max3][0];
					Happy3[max3][1]=-1; //更改已将排过的满意度为-1，可以保证比任何一个都小 
				}
				int golist[morestu][3]; //储存将要转部的学生，二维项0为学生下标，1为满意度 ，2要去的部 
				int last=morestu; //储存还剩几个
			
				while(last!=0){
					//判断在另一个备选名单中的自己的满意度是否大于这个名单中的，如果是的话就把自己删掉。 
					for(int j=0;j<used3;j++) if(px1[morestu-last][0]==px3[j][0] && px3[j][1]>px1[morestu-last][1]) px1[morestu-last][1]=-1;
					for(int j=0;j<used1;j++) if(px3[morestu-last][0]==px1[j][0] && px1[j][1]>px3[morestu-last][1]) px3[morestu-last][1]=-1;
					if(px1[morestu-last][1]>px3[morestu-last][1] && part1+1<=halfstu){
						golist[morestu-last][0]=px1[morestu-last][0];
						golist[morestu-last][1]=px1[morestu-last][1];
						golist[morestu-last][2]=2;
						part1++;
						part2--;
					}
					else if(px3[morestu-last][1]>px1[morestu-last][1] && part3+1<=halfstu){
						golist[morestu-last][0]=px3[morestu-last][0];
						golist[morestu-last][1]=px3[morestu-last][1];
						golist[morestu-last][2]=3;
						part3++;
						part2--;
					}
					last--; 
				}
				for(int j=0;j<morestu;j++){
					student[golist[j][0]].stupart=golist[j][2];
				} 
			}
			if(part3>halfstu){
				int morestu=part1-halfstu;  //至少需要挪走几个学生才可以满足要求 
				int Happy1[part3][2],Happy2[part3][2];  //该部门中所有成员对其他部门的满意值 ,其中二维0项为该学生下标，1项为满意度 
				//相当于问卷调查，填写 
				for(int j=0;j<part1;j++){
					Happy1[j][1]=student[j].part[1];
					Happy1[j][0]=j;
					Happy2[j][1]=student[j].part[2];   
					Happy2[j][0]=j;
				}
				int px1[part3][2],px2[part3][2]; //排序过后的对其他学院满意度调查 
				int used1=0,used2=0;  //已经用到的数组下标 
				int max1=0,max2=0; //最大值的下标 
				for(int j=0;j<part3;j++){
					for(int k=0;k<part3;k++){
						if(Happy1[k][1]>Happy1[max2][1]){
							max1=k;
						}
					}
					px1[used1][1]=Happy1[max1][1]; //搬到排序数组 
					px1[used1][0]=Happy1[max1][0];
					Happy1[max1][1]=-1; //更改已将排过的满意度为-1，可以保证比任何一个都小 
					//对3排序 
					for(int k=0;k<part3;k++){
						if(Happy2[k][1]>Happy2[max2][1]){
							max2=k;
						}
					}
					px2[used2][1]=Happy2[max2][1]; //搬到排序数组 
					px2[used2][0]=Happy2[max2][0];
					Happy2[max2][1]=-1; //更改已将排过的满意度为-1，可以保证比任何一个都小 
				}
				int golist[morestu][3]; //储存将要转部的学生，二维项0为学生下标，1为满意度 ，2要去的部 
				int last=morestu; //储存还剩几个
			
				while(last!=0){
					//判断在另一个备选名单中的自己的满意度是否大于这个名单中的，如果是的话就把自己删掉。 
					for(int j=0;j<used2;j++) if(px1[morestu-last][0]==px2[j][0] && px2[j][1]>px1[morestu-last][1]) px1[morestu-last][1]=-1;
					for(int j=0;j<used1;j++) if(px2[morestu-last][0]==px1[j][0] && px1[j][1]>px2[morestu-last][1]) px2[morestu-last][1]=-1;
					if(px1[morestu-last][1]>px2[morestu-last][1] && part1+1<=halfstu){
						golist[morestu-last][0]=px1[morestu-last][0];
						golist[morestu-last][1]=px1[morestu-last][1];
						golist[morestu-last][2]=2;
						part1++;
						part3--;
					}
					else if(px2[morestu-last][1]>px1[morestu-last][1] && part2+1<=halfstu){
						golist[morestu-last][0]=px2[morestu-last][0];
						golist[morestu-last][1]=px2[morestu-last][1];
						golist[morestu-last][2]=3;
						part2++;
						part3--;
					}
					last--; 
				}
				for(int j=0;j<morestu;j++){
					student[golist[j][0]].stupart=golist[j][2];
				} 
			}
		}
		
		
	} 
	for(int i=0;i<t;i++) cout<<out[i]<<" ";
	return 0;
} 
