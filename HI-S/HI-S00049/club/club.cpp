#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int hao1[500002];//好感度数组 
int hao2[500002]; 
int hao3[500002];
int y[5];//好感度总数 
int main(){
    freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
    
	
	
	
    int q1=0;//记录社团1的人数
	int q2=0;//记录社团2的人数
	int q3=0;//记录社团3的人数
	
	
	
    int t;//组数 
    cin>>t; 
	int n;
	for(int i=1;i<=t;i++){   //
	
		cin>>n;
		int f=n/2;//最多有多少人能进社团 
		for(int j=1;j<=n;j++){
			cin>>hao1[j];
			cin>>hao2[j];
			cin>>hao3[j];
			if(hao1[j]>hao2[j]&&hao1[j]>hao3[j]){			//求出最大好感度 
				
				if(q1>f){
					y[i]=y[i]-=hao1[j];
				}
				   //超出人数就别来
				q1++;
                y[i]=y[i]+=hao1[j]; 
				
			}
			else if(hao2[j]>hao1[j]&&hao2[j]>hao3[j]){
                
				if(q1>f){
					y[i]=y[i]-=hao1[j];
				}//超出人数就别来
				
				q2++;
                y[i]=y[i]+=hao2[j]; 
				
			}
			else if(hao3[j]>hao1[j]&&hao3[j]>hao2[j]){
				if(q1>f){
					y[i]=y[i]-=hao1[j];
				} //超出人数就别来
				
					q3++;
				    y[i]=y[i]+=hao3[j]; 
				
			}
            
		}
	} 
	for(int i=1;i<=t;i++){
		cout<<y[i]<<endl;
	}
	
	
	return 0;
}

