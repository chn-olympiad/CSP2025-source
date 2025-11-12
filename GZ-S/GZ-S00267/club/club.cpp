//GZ-S00267 遵义市播州区南白初级中学 杨朝涵
#include<bits/stdc++.h>
using namespace std;
int arr1[5][100000][3],xia=0;//主数组 
int arr3[10000],pl=0;//下标 
int len=0;

int get_max_value(int t_num,int t_members){
	int max_value=0;
	for(int j=0;j<3;++j){
		if(max_value<arr1[t_num][t_members][j]){
			max_value=arr1[t_num][t_members][j];
			xia=j;
			arr3[0+pl]=xia;
			pl++;
		} 
	}
	len++;
	return max_value;
}

int fin(){
	int a1=0,a2=0,a3=0;
	for(int i=0;i<pl;++i){
		if(arr3[i]==0){
			a1++;
		}
		if(arr3[i]==1){
			a2++;
		}
		if(arr3[i]==2){
			a3++;
		}
	}
	if(a1>a1/2){
		//
	}
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 

	int t,n,a;
	int arr2[9999]={};//最大值数组 

	cin>>t>>n;
	
	for(int i=0;i<t;++i){
		for(int p=0;p<n;++p){
			for(int j=0;j<3;++j){
				cin>>a;
				arr1[i][p][j]=a; 
			}
		}
	}
	
	int lp=0,ab=0;
	for(int i=0;i<t;++i){
		for(int p=0;p<n;++p){
			ab=get_max_value(i,p);
			arr2[0+lp]=ab;
			lp++;
		}
	}
	
	int alnum=0;
	for(int i=0;i<len;++i){
		alnum=alnum+arr2[i];
	}
	cout<<alnum<<endl;
	return 0;
}





