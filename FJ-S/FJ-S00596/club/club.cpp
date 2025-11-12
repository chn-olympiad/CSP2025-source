#include <bits/stdc++.h> 
using namespace std;
int n[7],cy[7],a[100005][7][5],cha[100005],club1,club2,club3,t,sum,tf[100005],tf1,max1,max2,jishu[50005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		cy[i]=n[i]/2;
		for(int j=1;j<=n[i];j++){
			cin>>a[j][i][1]>>a[j][i][2]>>a[j][i][3];
			max1=max(a[j-1][i][2],a[j][i][2]);
			max2=max(a[j-1][i][3],a[j][i][3]);
			tf[j]=a[j][i][1];
		}
		sort(tf+1,tf+n[i]+1);
		for(int j=n[i];j>(n[i]/2);j--){
			tf1=tf[j]+tf1;
		}
		if(max1==0 && max2==0){
		cout<<tf1<<endl;
		n[i]=0;
		}
	}
	
		club1=0;
		club2=0;
		club3=0;
		for(int i=1;i<=t;i++){
			if(n[i]==2){
			sum=max(a[1][i][1]+a[2][i][2],a[1][i][1]+a[2][i][3]);
			sum=max(sum,a[1][i][2]+a[2][i][3]);
			sum=max(sum,a[1][i][2]+a[2][i][1]);
			sum=max(sum,a[1][i][3]+a[2][i][2]);
			sum=max(sum,a[1][i][3]+a[2][i][1]);
			cout<<sum<<endl;
		}
		if(n[i]==4){
			sum=max(a[1][i][1]+a[2][i][1]+a[3][i][2]+a[4][i][2],a[1][i][1]+a[2][i][1]+a[3][i][2]+a[4][i][3]);
			sum=max(sum,a[1][i][1]+a[2][i][1]+a[3][i][3]+a[4][i][3]);
			sum=max(sum,a[1][i][1]+a[2][i][1]+a[3][i][3]+a[4][i][2]);
			sum=max(sum,a[1][i][1]+a[2][i][1]+a[3][i][3]+a[4][i][3]);
			sum=max(sum,a[1][i][1]+a[2][i][2]+a[3][i][1]+a[4][i][2]);
			sum=max(sum,a[1][i][1]+a[2][i][2]+a[3][i][1]+a[4][i][3]);
			sum=max(sum,a[1][i][1]+a[2][i][2]+a[3][i][2]+a[4][i][1]);
			sum=max(sum,a[1][i][1]+a[2][i][2]+a[3][i][2]+a[4][i][3]);
			sum=max(sum,a[1][i][1]+a[2][i][2]+a[3][i][3]+a[4][i][1]);
			sum=max(sum,a[1][i][1]+a[2][i][2]+a[3][i][3]+a[4][i][2]);
			sum=max(sum,a[1][i][1]+a[2][i][2]+a[3][i][3]+a[4][i][3]);
			sum=max(sum,a[1][i][1]+a[2][i][3]+a[3][i][1]+a[4][i][2]);
			sum=max(sum,a[1][i][1]+a[2][i][3]+a[3][i][1]+a[4][i][3]);
			sum=max(sum,a[1][i][1]+a[2][i][3]+a[3][i][2]+a[4][i][2]);
			sum=max(sum,a[1][i][1]+a[2][i][3]+a[3][i][2]+a[4][i][3]);
			sum=max(sum,a[1][i][1]+a[2][i][3]+a[3][i][3]+a[4][i][1]);
			sum=max(sum,a[1][i][1]+a[2][i][3]+a[3][i][3]+a[4][i][2]);
			sum=max(sum,a[1][i][2]+a[2][i][1]+a[3][i][1]+a[4][i][2]);
			sum=max(sum,a[1][i][2]+a[2][i][1]+a[3][i][1]+a[4][i][3]);
			sum=max(sum,a[1][i][2]+a[2][i][1]+a[3][i][2]+a[4][i][1]);
			sum=max(sum,a[1][i][2]+a[2][i][1]+a[3][i][2]+a[4][i][3]);
			sum=max(sum,a[1][i][2]+a[2][i][1]+a[3][i][3]+a[4][i][1]);
			sum=max(sum,a[1][i][2]+a[2][i][1]+a[3][i][3]+a[4][i][2]);
			sum=max(sum,a[1][i][2]+a[2][i][1]+a[3][i][3]+a[4][i][3]);
			sum=max(sum,a[1][i][2]+a[2][i][2]+a[3][i][1]+a[4][i][1]);
			sum=max(sum,a[1][i][2]+a[2][i][2]+a[3][i][1]+a[4][i][3]);
			sum=max(sum,a[1][i][2]+a[2][i][2]+a[3][i][3]+a[4][i][1]);
			sum=max(sum,a[1][i][2]+a[2][i][2]+a[3][i][3]+a[4][i][3]);
			sum=max(sum,a[1][i][2]+a[2][i][3]+a[3][i][1]+a[4][i][1]);
			sum=max(sum,a[1][i][2]+a[2][i][3]+a[3][i][1]+a[4][i][2]);
			sum=max(sum,a[1][i][2]+a[2][i][3]+a[3][i][1]+a[4][i][3]);
			sum=max(sum,a[1][i][2]+a[2][i][3]+a[3][i][2]+a[4][i][1]);
			sum=max(sum,a[1][i][2]+a[2][i][3]+a[3][i][2]+a[4][i][3]);
			sum=max(sum,a[1][i][2]+a[2][i][3]+a[3][i][3]+a[4][i][1]);
			sum=max(sum,a[1][i][2]+a[2][i][3]+a[3][i][3]+a[4][i][2]);
			sum=max(sum,a[1][i][3]+a[2][i][1]+a[3][i][1]+a[4][i][2]);
			sum=max(sum,a[1][i][3]+a[2][i][1]+a[3][i][1]+a[4][i][3]);
			sum=max(sum,a[1][i][3]+a[2][i][1]+a[3][i][2]+a[4][i][1]);
			sum=max(sum,a[1][i][3]+a[2][i][1]+a[3][i][2]+a[4][i][2]);
			sum=max(sum,a[1][i][3]+a[2][i][1]+a[3][i][2]+a[4][i][3]);
			sum=max(sum,a[1][i][3]+a[2][i][1]+a[3][i][3]+a[4][i][1]);
			sum=max(sum,a[1][i][3]+a[2][i][1]+a[3][i][3]+a[4][i][2]);
			sum=max(sum,a[1][i][3]+a[2][i][2]+a[3][i][1]+a[4][i][1]);
			sum=max(sum,a[1][i][3]+a[2][i][2]+a[3][i][1]+a[4][i][2]);
			sum=max(sum,a[1][i][3]+a[2][i][2]+a[3][i][1]+a[4][i][3]);
			sum=max(sum,a[1][i][3]+a[2][i][2]+a[3][i][2]+a[4][i][1]);
			sum=max(sum,a[1][i][3]+a[2][i][2]+a[3][i][2]+a[4][i][3]);
			sum=max(sum,a[1][i][3]+a[2][i][2]+a[3][i][3]+a[4][i][1]);
			sum=max(sum,a[1][i][3]+a[2][i][2]+a[3][i][3]+a[4][i][2]);
			sum=max(sum,a[1][i][3]+a[2][i][3]+a[3][i][1]+a[4][i][1]);
			sum=max(sum,a[1][i][3]+a[2][i][3]+a[3][i][1]+a[4][i][2]);
			sum=max(sum,a[1][i][3]+a[2][i][3]+a[3][i][2]+a[4][i][1]);
			sum=max(sum,a[1][i][3]+a[2][i][3]+a[3][i][2]+a[4][i][2]);
			cout<<sum<<endl;
		}
		
		
			sum=0;
		}
	return 0;
} 
