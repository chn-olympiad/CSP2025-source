#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n]={};
	for(int i=0;i<n;){
		cin>>a[i];
		i++;
	} 
	if(n<=3){
		if(n<=2){
			cout<<0;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}else if(a[0]+a[1]+a[2]>2*a[0]&&a[0]+a[1]+a[2]>2*a[1]&& a[0]+a[1]+a[2]>2*a[2]){
			cout<<1;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}else{
			cout<<0;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	if(n==4){
		int sum=0;
		if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2]))){
			sum++;
		}
		if(a[0]+a[1]+a[3]>2*max(a[0],max(a[1],a[3]))){
			sum++;
		}
		if(a[3]+a[1]+a[2]>2*max(a[3],max(a[1],a[2]))){
			sum++;
		}
		cout<<sum;
			fclose(stdin);
			fclose(stdout);
			return 0;
	}
	if(n==5){
		int sum=0;
		if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2]))){
			sum++;
		}
		if(a[0]+a[1]+a[3]>2*max(a[0],max(a[1],a[3]))){
			sum++;
		}
		if(a[0]+a[1]+a[4]>2*max(a[0],max(a[1],a[4]))){
			sum++;
		}
		if(a[0]+a[2]+a[3]>2*max(a[0],max(a[2],a[3]))){
			sum++;
		}
		if(a[0]+a[2]+a[4]>2*max(a[0],max(a[2],a[4]))){
			sum++;
		}
		if(a[0]+a[3]+a[4]>2*max(a[0],max(a[3],a[4]))){
			sum++;
		}
		if(a[3]+a[1]+a[2]>2*max(a[3],max(a[1],a[2]))){
			sum++;
		}
		if(a[4]+a[1]+a[2]>2*max(a[4],max(a[1],a[2]))){
			sum++;
		}
		if(a[4]+a[1]+a[3]>2*max(a[4],max(a[1],a[3]))){
			sum++;
		}
		if(a[4]+a[3]+a[2]>2*max(a[4],max(a[3],a[2]))){
			sum++;
		}
		if(a[0]+a[1]+a[2]+a[3]>2*max(a[0],max(a[1],max(a[2],a[3])))){
			sum++;
		}
		if(a[0]+a[1]+a[2]+a[4]>2*max(a[0],max(a[1],max(a[2],a[4])))){
			sum++;
		}
		if(a[0]+a[1]+a[3]+a[4]>2*max(a[0],max(a[1],max(a[3],a[4])))){
			sum++;
		}
		if(a[0]+a[2]+a[3]+a[4]>2*max(a[0],max(a[2],max(a[3],a[4])))){
			sum++;
		}
		if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],a[4])))){
			sum++;
		}
		if(a[0]+a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],max(a[4],a[5]))))){
			sum++;
		}
		cout<<sum;
			fclose(stdin);
			fclose(stdout);
			return 0;
	}
	return 0;
}

