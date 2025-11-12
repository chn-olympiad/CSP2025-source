#include<iostream>
#include<vector>
using namespace std;

int midd(int a,int b,int c,int j){
	int i;
	int Max=0;
	for(i=0;i<3;i++){
		if(j!=i){
		
		if(i==0){
			if(Max<a)Max=a;
		}else if(i==1){
			if(Max<b)Max=b;
		}else if(i==2){
			if(Max<c)Max=c;
		}}
	}
	return Max;
}

int main(){
	freopen("D:\GD-S00944\club\club.in","r",stdin);
	freopen("D:\GD-S00944\club\club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int d[1000][3];
		for(int i=0;i<n;i++){
			cin>>d[i][0]>>d[i][1]>>d[i][2];
		}
		
		int max[1000];
		int min[1000];
		for(int i=0;i<1000;i++){
			max[i]=0;
			min[i]=0;
		}
		if(n==2){
			int r[2]={3,4};
			for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(max[i]<d[i][j])max[i]=d[i][j];
			}
			
		for(int j=0;j<3;j++)
				if(max[i]==d[i][j]){
					r[i]=j;
				}
		}if(r[0]==r[1]){
				if(max[0]+midd(d[1][0],d[1][1],d[1][2],r[0])<max[1]+midd(d[0][0],d[0][1],d[0][2],r[0]))max[0]=midd(d[0][0],d[0][1],d[0][2],r[0]);
				else max[1]=midd(d[1][0],d[1][1],d[1][2],r[0]);
		}
			
		}

		else {
			int res[3]={0,0,0};
			//int temp[3][3]={{0,0,0},{0,0,0},{0,0,0}};
			//int minT[3]={0,0,0};
			for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(max[i]<d[i][j]&&res[j]<n/2)max[i]=d[i][j];
			}
			
			
			for(int j=0;j<3;j++)
				if(max[i]==d[i][j]){
					res[j]++;
					break;
				}
		/*	for(int j=0;j<3;j++){
				if(res[j]>=n/2){
					if(temp[j][j]+midd(d[i][0],d[i][1],d[i][2],j)>max[i]+midd(temp[j][0],temp[j][1],temp[j][2],j)){
						max[i]=midd(d[i][0],d[i][1],d[i][2],j);
						for(int m=0;m<3;m++){
							temp[j][m]=d[i][m];
						}
						minT[j]=i;
					}
					else if(temp[j][j]+midd(d[i][0],d[i][1],d[i][2],j)<max[i]+midd(temp[j][0],temp[j][1],temp[j][2],j)){
						max[minT[j]]=midd(d[minT[j]][0],d[minT[j]][1],d[minT[j]][2],j);
					}
				}
			}*/	
		}
		for(int i=0;i<3;i++){
			res[i]=0;
		}
			for(int i=n-1;i>=0;i--){
			for(int j=0;j<3;j++){
				if(min[i]<d[i][j]&&res[j]<n/2)min[i]=d[i][j];
			}
			
			
			for(int j=0;j<3;j++)
				if(min[i]==d[i][j]){
					res[j]++;
					break;
				}
				
		}
		
		}
		
		int ans=0;
		int ans1=0;
		for(int i=0;i<n;i++){
			//cout<<max[i]<<" ";
			ans+=max[i];
			ans1+=min[i];
		}
		if(ans<ans1)ans=ans1;
		cout<<ans<<endl;
		
	}
	//Ren5Jie4Di4Ling5%
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
