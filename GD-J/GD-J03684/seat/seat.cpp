#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,m,d[105]; 
int r;//小R的成绩 
bool cmp(int x,int y){//从大到小排序 
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>d[i];
		if(i==1){
			r=d[i];//记录 小R成绩 
		}
	} 
	
	sort(d+1,d+n*m+1,cmp);//排序 
	
	
	int x;//小R在第几个 
	for(int i=1;i<=n*m;i++){
		if(d[i]!=r) continue;
		x=i;
		break; 
	}
	int t=1;//找位置 
	
	bool flag=false;
	for(int i=1;i<=m;i++){//列 
		if(flag) break;
		if(i%2!=0){//第i列奇数，行递增 
			for(int j=1;j<=n;j++){
			    
				if(t==x){//小R的位置 
					cout<<i<<" "<<j<<endl; 
					flag=true;
					break; 
				}else{
					t++;
				}
			}
		}else{//列偶数，行递减 
			for(int j=n;j>=1;j--){
				//a[i][j]=d[t++];
				if(t==x){//小R的位置 
					cout<<i<<" "<<j<<endl; 
					flag=true;
					break;
				}else{
					t++;
				}
			}
		} 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
