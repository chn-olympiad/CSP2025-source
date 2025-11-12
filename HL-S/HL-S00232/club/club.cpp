#include <bits/stdc++.h>
int arr[100010][4];
bool ar[100010][4];
int shu[100010];
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	
	
	for(int i=0;i<t;i++){
		int sum=0;	
		int n=0;
		cin>>n;
		int a[4]={0,0,0,0};
		for(int j=1;j<=n;j++){
		cin>>arr[j][1];
		cin>>arr[j][2];
		cin>>arr[j][3];	
	}
	
	for(int j=1;j<=n;j++){
			int zuida=0;
			if(arr[j][1]>=arr[j][2]&&arr[j][1]>=arr[j][3]){
				a[1]++;
				zuida=arr[j][1];
				ar[j][1]++; 
				
			}
			else if(arr[j][2]>arr[j][1]&&arr[j][2]>arr[j][3]){
				a[2]++;
				zuida=arr[j][2];
				ar[j][2]++;
			}
			else if(arr[j][3]>arr[j][2]&&arr[j][3]>arr[j][1]){
				a[3]++;
				zuida=arr[j][3];
				ar[j][3]++;
			}
			for(int k=1;k<=3;k++){
				arr[j][k]-=zuida;
			}
			sum+=zuida;
	}
	
	
	

	
	
	
	int most=max(a[1], max(a[2],a[3]) );
	
	if(n/2<most){
		
		
		if(n/2<a[1]){
			int p=a[1];
			int a=0; 
			for(int j=1,aa=1;j<=n;j++){
			if(ar[j][1]){
			if(arr[j][2]>arr[j][3])
			shu[aa]=arr[j][2];
			else shu[aa]=arr[j][3];
			aa++;
			}
			
			}
			sort(shu+1,shu+1+p);
			
			int num=p-n/2;
			
			for(int h=p;h>num;h--){
			sum+=shu[h];
			}
			
			}	
		else if(n/2<a[2]){
			int p=a[2];
			int a=0; 
			for(int j=1,aa=1;j<=n;j++){
			if(ar[j][2]){
			if(arr[j][1]>arr[j][3])
			shu[aa]=arr[j][1];
			else shu[aa]=arr[j][3];
			aa++;
			}
			
			}
			sort(shu+1,shu+1+p);
			
			int num=p-n/2;
			
			for(int h=p;h>num;h--){
			sum+=shu[h];
			}
			
			}	
		
		else if(n/2<a[3]){
			int p=a[3];
			int a=0; 
			for(int j=1,aa=1;j<=n;j++){
			if(ar[j][3]){
			if(arr[j][1]>arr[j][2])
			shu[aa]=arr[j][1];
			else shu[aa]=arr[j][2];
			aa++;
			}
			
			}
			sort(shu+1,shu+1+p);
			
			int num=p-n/2;
			
			for(int h=p;h>num;h--){
			sum+=shu[h];
			}
			
			}	
	
		
	
	
	
		
	}
	
	cout<<sum<<endl;
}
	return 0;

}
