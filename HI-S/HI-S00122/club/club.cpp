#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n[t],a[10010][3],num1,num2,num3,b[t],num4;
	for(int k=0;k<t;k++){
		cin>>n[k];
		for(int i=0;i<n[k];i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
			
			}
			if(n[k]==2){
				num1=max(a[0][0]+a[1][1],a[0][0]+a[1][2]);
				num2=max(a[0][1]+a[1][0],a[0][1]+a[1][2]);
				num3=max(a[0][2]+a[1][1],a[0][2]+a[1][0]);
				num1=max(num1,num2);
				num1=max(num1,num3);
				b[k]=num1;
				num1=0;
			}
			else{
				for(int l=0;l<n[k];l++){
					num4=max(a[l][0],a[l][1]);
					num4=max(num4,a[l][2]);
					num1+=num4;
				}
				b[k]=num1;
			num1=0;
		}
	}
	for(int i=0;i<t;i++){
		cout<<b[i];
		if(i!=t-1){
			cout<<endl;
		}
	}
	return 0;
}

