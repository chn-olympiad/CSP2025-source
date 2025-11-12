//freopen("club.in","r",stdin);
//freopen("club.out","w",stdout);
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t,n;
	int a[3]={1,2,3};
	cin>>t>>n;
	for(int i=0;i<t;++t){
		int cnt=0; 
		for(int i=0;i<n;++i){
			int a1,a2,a3;
			printf("%d %d %d",a1,a2,a3);
			if(a1>=a2&&a1>=a3){
				a[0]++;
				cnt+=a1;
			}else if(a2>=a1&&a2>=a3){
				a[1]++;
				cnt+=a2;
			}else if(a3>=a1&&a3>=a2){
				a[2]++;
				cnt+=a3;
			}
		}
		if(a[0]<=(n/2)&&a[1]<=(n/2)&&a[2]<=(n/2)){
			cout<<cnt<<endl;
		}
	}
	return 0;
} 
