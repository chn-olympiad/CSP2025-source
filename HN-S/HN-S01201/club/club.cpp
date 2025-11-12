#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],b[1001][1001],c[1001][1001];
int sum1[100][100]={},sum2[100][100]={},sum3[100][100]={};	
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	int n[1001];
	for(int i=0;i<t;i++){
		cin>>n[i];
		for(int j=0;j<n[i];j++){
			cin>>a[i][j]>>b[i][j]>>c[i][j];
		}
	}
	for(int i=0;i<t;i++){
		int num1=0,num2=0,num3=0;
		for(int j=0;j<n[i];j++){
			if(n[i]/2>=sum1[i][j]){
				if(a[i][j]>b[i][j] && a[i][j]>c[i][j]){
					sum1[i][j]+=a[i][j];
					num1++;
				}
			}
			else if(n[i]/2>=sum2[i][j]){
				if(a[i][j]<b[i][j] && b[i][j]>c[i][j]){
					sum2[i][j]+=a[i][j];
					num2++;
				}
			}
			else if(n[i]/2>=sum3[i][j]){
				if(c[i][j]>b[i][j] && a[i][j]<c[i][j]){
					sum3[i][j]+=a[i][j];
					num3++;
				}
			}
		}
		if(num1>num2 && num1>num3){
			cout<<sum1<<endl;
		}
		else if(num1<num2 && num2>num3){
			cout<<sum2<<endl;
		}
		else if(num3>num2 && num1<num3){
			cout<<sum3<<endl;
		}
	}	
	return 0;
}
