#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
int t;            //测试数据数量 
int n;            //新成员数量 
int a[MAXN][4];   //每位成员对三个部门满意度  
int my1, my2, my3;//满意度
int p1, p2, p3;   //人数
int maxp;         //最大人数(n/2) 


void dfs(){                                                //查找最合适的（不完善） 
	for(int i = 0; i <= n; i++){                           //用i遍历数组 
		if(a[i][1] > a[i][2] && a[i][1] > a[i][3]){		   //如果第 i个人对第1个部门的满意度比其他两个高 
			if(p1 < maxp){								   //如果第 1个部门还能招人 
				my1 += a[i][1];                            //把这个人加入 1部门 
				p1++;									   //人数加 1 
			}
			else{                                          //如果不能招人 
				if(a[i][2] > a[i][3] && p2 < maxp){        //如果第 2个部门的兴趣比第 3个部门高 
					my2 += a[i][2];                        //把这个人加入 2部门 
					p2++;								   //人数加 1 
				}
				else if(p3 < maxp){						   //如果对第三个部门兴趣高且第三个部门能招人  
					my3 += a[i][3];						   
					p3++;
				}
			}
		}
		else if(a[i][2] > a[i][1] && a[i][2] > a[i][3] && p2 < maxp){
			if(p2 < maxp){
				my2 += a[i][2];
				p2++;
			}
			else{
				if(a[i][1] > a[i][3] && p1 < maxp){
					my1 += a[i][1];
					p1++;
				}
				else if(p3 < maxp){
					my3 += a[i][3];
					p3++;
				}
			}
		}
		else if(a[i][3] > a[i][2] && a[i][3] > a[i][1] && p3 < maxp){
			if(p3 < maxp){
				my3 += a[i][3];
				p3++;
			}
			else{
				if(a[i][1] > a[i][2] && p1 < maxp){
					my1 += a[i][1];
					p1++;
				}
				else if(p2 < maxp){
					my2 += a[i][2];
					p2++;
				}
			}
		}
	}
}





int main(){
    ios::sync_with_stdio(false);
    freopen("club.in",  "r", stdin);
    //freopen("club.out", "w", stdout);
    cin>>t;
    for(int i = 0; i < t; i++){             //总循环（测试点数量）
		my1 = 0;my2 = 0;my3 = 0;
		cin>>n;
		maxp = n/2;
    	for(int j = 0; j < n; j++){         //输入三个部门满意度 
    		cin>>a[j][1]>>a[j][2]>>a[j][3];
		}	
		dfs();
		cout<<my1+my2+my3<<endl;
	} 
    
    
    return 0; 
}
