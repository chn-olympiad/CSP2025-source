#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int num_max;
	int a[5005];
	int num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		num_max=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3] > 2*num_max){
			num++;
		}
	}
	if(n==4){
		num_max=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[1],a[3]),a[4]);
		if(a[1]+a[4]+a[3] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[4],a[2]),a[3]);
		if(a[4]+a[2]+a[3] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[1],a[2]),a[4]);
		if(a[1]+a[2]+a[4] > 2*num_max){
			num++;
		}
		
		num_max=max(a[3],max(max(a[1],a[2]),a[4]));
		if(a[1]+a[2]+a[3]+a[4] > 2*num_max){
			num++;
		}
		
	}
	
	if(n==5){
		num_max=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[1],a[2]),a[4]);
		if(a[1]+a[2]+a[4] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[1],a[2]),a[5]);
		if(a[1]+a[2]+a[5] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[1],a[3]),a[4]);
		if(a[1]+a[3]+a[4] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[1],a[5]),a[4]);
		if(a[1]+a[5]+a[4] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[1],a[3]),a[5]);
		if(a[1]+a[3]+a[5] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[3],a[2]),a[4]);
		if(a[3]+a[2]+a[4] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[3],a[2]),a[5]);
		if(a[3]+a[2]+a[5] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[5],a[2]),a[4]);
		if(a[5]+a[2]+a[4] > 2*num_max){
			num++;
		}
		
		num_max=max(max(a[3],a[5]),a[4]);
		if(a[3]+a[5]+a[4] > 2*num_max){
			num++;
		}
		//4¸ö
		num_max=max(a[3],max(max(a[1],a[2]),a[4]));
		if(a[1]+a[2]+a[3]+a[4] > 2*num_max){
			num++;
		}
		
		num_max=max(a[3],max(max(a[1],a[2]),a[5]));
		if(a[1]+a[2]+a[3]+a[5] > 2*num_max){
			num++;
		}
		
		num_max=max(a[5],max(max(a[1],a[2]),a[4]));
		if(a[1]+a[2]+a[5]+a[4] > 2*num_max){
			num++;
		}
		
		num_max=max(a[3],max(max(a[1],a[5]),a[4]));
		if(a[1]+a[5]+a[3]+a[4] > 2*num_max){
			num++;
		}
		
		num_max=max(a[3],max(max(a[5],a[2]),a[4]));
		if(a[5]+a[2]+a[3]+a[4] > 2*num_max){
			num++;
		}
		//5
		num_max=max(a[5],max(a[3],max(max(a[1],a[2]),a[4])));
		if(a[1]+a[2]+a[3]+a[4]+a[5] > 2*num_max){
			num++;
		}
	}
	cout<<num;
	return 0;
} 
