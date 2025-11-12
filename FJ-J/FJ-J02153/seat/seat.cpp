#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],cent,b[15][15];//cent小r分数
bool cmp(int x,int y){
	return x>y;
} 
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]); 
		if(i==1) cent=a[i];  
	} 
//	cout<<"cent is"<<cent<<endl;
	sort(a+1,a+n*m+1,cmp);//排序 
//	for(int i=1;i<=n*m;i++){
//		printf("%d ",a[i]);
//	} 
//	cout<<cent;
	bool der=1;
	//der是derection 方向 1代表向下，0代表向上
//	2 3
//	11 45 14 78 91 630 
//	--------------------
//	1  2  3  4  5  6
//	11 14 45 78 91 630
//	
//	   1    2   3
//	1 630  45  14
//	2 91   78  11

	int j=1,i=1;
	for(int t=1;t<=n*m;t++){
		
//		cout<<i<<" "<<j<<" "<<der<<" "<<a[t]<<endl; 
//		for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl; 
//		}
		
	
	
		if((i==(n+1))||i==0) {//如果走到头 
			j++;//列数增加 
			der=!der;//方向改为 相反的 
			if(i==n+1) i=n;
			else if(i==0)i=1;
		
		}
		if(a[t]==cent) {
			cout<<j<<" "<<i<<endl;
			break;
		}
		b[i][j]=a[t];//座位的ij打上分数
		if(der==1) i++;//如果向下i++ 
		else if(der==0) i--;//如果向上i-- 
		
		
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl; 
//	}
	return 0;
} 
