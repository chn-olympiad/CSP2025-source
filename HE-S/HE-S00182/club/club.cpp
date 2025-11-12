#include<iostream>
using namespace std;
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	int a1,a2,a3,a11=0,a22=0,a33=0,sum=0,cnt=0;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cnt++;
			cin>>a1>>a2>>a3;
			if(a1>a2&&a1>a3){
				a11+=1;
			}else if(a2>a1&&a2>a3){
				a22+=1;
			}else{
				a33+=1;
			}
			if(max(max(a11,a22),a33)>n/2){
				max(max(a11,a22),a33)-=1;
				min(min(a11,a22),a33)+=1;
				sum+=min(max(a1,a2),a3);
			}
			else{
				sum+=max(max(a1,a2),a3);	
			}
			if(cnt==n){
				cout<<sum;
				sum=0;
				a11=0;
				a22=0;
				a33=0;
				cnt=0;
			}
		}
	}
	return 0;
}
