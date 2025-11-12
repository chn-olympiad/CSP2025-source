#include<bits/stdc++.h>
using namespace std;
int a[100010][5];
//int m_sum_max;
//bool cmp(int x[100010][4],int y[100010][4],int i){
//	return x[i][0]>y[i][0];
//}
void s(int k){
	int temp=0;
	for(int i=0;i<k;i++){
		temp=0;
		for(int j=0;j<k-1;j++){
			if(a[j][4]>=a[j+1][4])temp++;
			if(a[j][4]<a[j+1][4]){
				for(int q=0;q<5;q++){
					swap(a[j][q],a[j+1][q]);
				}
			}
		}
		if(temp==k)return;
	}
}
int f(int n){
	int sum=0;
	int d1=0,d2=0,d3=0;
	for(int i=0;i<n;i++){
		if(a[i][0]==a[i][1]){
//			sum+=a[i][0];
//			d1++;
			if(d1<n/2){
				sum=sum+a[i][0];
				d1++;
			}else if(a[i][2]>a[i][3]){
				sum=sum+a[i][2];
				d2++;
			}else{
				sum=sum+a[i][3];
				d3++;
			}
		}else if(a[i][0]==a[i][2]){
//			sum+=a[i][0];
//			d2++;
			if(d2<n/2){
				sum=sum+a[i][0];
				d2++;
			}else if(a[i][1]>a[i][3]){
				sum=sum+a[i][1];
				d1++;
			}else{
				sum=sum+a[i][3];
				d3++;
			}
		}else{
//			sum+=a[i][0];
//			d3++;
			if(d3<n/2){
				sum+=a[i][0];
				d3++;
			}else if(a[i][2]>a[i][1]){
				sum+=a[i][2];
				d2++;
			}else{
				sum+=a[i][1];
				d1++;
			}
		}
	}
//	if(d1>n/2){
//		
//	}
	return sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n[5]={};
	for(int k=0;k<t;k++){
		cin>>n[k];
		for(int j=0;j<n[k];j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			if(a[j][1]>=a[j][2]&&a[j][1]>=a[j][3]){
				a[j][0]=a[j][1];
				if(a[j][2]>=a[j][3]){
					a[j][4]=a[j][0]-a[j][2];
				}else a[j][4]=a[j][0]-a[j][3];
			}
			else if(a[j][2]>=a[j][3]){
				a[j][0]=a[j][2];
				if(a[j][1]>=a[j][3]){
					a[j][4]=a[j][0]-a[j][1];
				}
			}
			else{
				a[j][0]=a[j][3];
				if(a[j][1]>=a[j][2]){
					a[j][4]=a[j][0]-a[j][1];
				}
			}
		}
		s(n[k]);
		//
//		for(int i=0;i<n[k];i++){
//			for(int j=0;j<5;j++){
//				cout<<a[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		//
//		sort(a,a+n[i],cmp);
		cout<<f(n[k])<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
