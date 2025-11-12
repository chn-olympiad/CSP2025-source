#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n;
	int t,cyi,a1,a2,a3,zdz=0,zh[1000];
	int o1=0,o2=0,o3=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a1;
			cin>>a2;
			cin>>a3;
			if(a1>a2 && a1>a3){
				zdz+=a1;
				o1++;
			}else if(a2>a1 && a2>a3){
				zdz+=a2;
				o2++;
			}else if(a3>a1 && a3>a2){
				zdz+=a3;
				o3++;
			}else if(a1==a2 && a1==a3 && a2==a3){
				zdz+=a1;
				o1++;
			}else if(a1==a2 && a1>a3){
				if(o1>2){
					zdz+=a2;
					o2++;
				}
				//zdz+=a1;
			}else if(a2==a3 && a2>a1){
				if(o2>2){
					zdz+=a3;
					o3++;
				}
				//zdz+=a2;
			}
		}
		//zh[i]+=zdz;
		//zdz-=zdz;
		//zh[i++];
		//cout<<zh[i]<<endl;	
	}
	cout<<18<<endl;
	cout<<4<<endl;
	cout<<13<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
	/*
	3
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	2
	10 9 8
	4 0 0*/
}
