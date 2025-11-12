#include <bits/stdc++.h>
using namespace std;
int a[300005],mark[300005];
bool mb[300005];
int first,second,third;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;//t为测试数据组数 
	cin>>t;
	int n;//n为新成员数量 
	const int balence=n/2;
	int cnt=1;
	int sum=0;
	for(int i=1;i<=t;i++){
		cin>>n;
		cnt=0;
		for(int j=1;j<=3*n;j++){
			mb[j]=0;
			cin>>a[j];
			mark[j]=cnt;
			if(j%3==0) cnt++;			
		}
		sort(a+1,a+1+3*n,cmp);
		sort(mark,mark+1+3*n,cmp);
		for(int z=1;z<=3*n;z++){
			if(first==1 && second==1 && third==1) break;
			if(mb[z]==0){			
			
				if(mark[z]==1){
					first++;
				}else if(mark[z]==2){
					second++;
				}else{
					third++;
				}
				if(first>balence){
					for(int o=z+1;o<=3*n;o++){
						if(mark[o]==first){
						  if(second==0){
						  	second++;
						  }else{
						  	third++;
						  }
						}
					}
					continue;
				}
				if(second>balence){
					for(int o=z+1;o<=3*n;o++){
						if(mark[o]==second){
							if(third==0){
						  	third++;
						  }else{
						  	first++;
						  }
						  
						}
					}
					mb[z]==1;
					continue;
				}
				if(third>balence){
					for(int o=z+1;o<=3*n;o++){
						if(mark[o]==second){
							if(first==0){
						  	first++;
						  }else{
						  	second++;
						  }
						  
						}
					}
					mb[z]==1;
					continue;
				}
				if(third>balence){
					for(int o=z+1;o<=3*n;o++){
						if(mark[o]==third){
						  third++;
						}
					}
					mb[z]==1;
					continue;
				}
				mb[z]==1;
				sum+=a[z];
			}
		}
	}				
	cout<<sum;
	return 0;
}
