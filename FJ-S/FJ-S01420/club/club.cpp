#include<bits/stdc++.h>
using namespace std;
int T,a,x[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for (int i=0;i<T;i++){
		cin>>a;
		for (int j=0;j<a;j++){
			cin>>x[j][0]>>x[j][1]>>x[j][2];
		}
		if (a==2){
			int max0=max(x[0][0],max(x[0][1],x[0][2]));
			int max1=max(x[1][0],max(x[1][1],x[1][2]));
			int min0=min(x[0][0],min(x[0][1],x[0][2]));
			int min1=min(x[1][0],min(x[1][1],x[1][2]));
			if (max0==x[0][0] && max0!=x[0][1] && max0!=x[0][2] && max1==x[1][0] && max1!=x[1][1] && max1!=x[1][2]){
				cout<<max(max0+(x[1][0]+x[1][1]+x[1][2])-max1-min1,max1+(x[0][0]+x[0][1]+x[0][2]-max0-min0))<<endl;
			}
			else if (max0!=x[0][0] && max0==x[0][1] && max0!=x[0][2] && max1!=x[1][0] && max1==x[1][1] && max1!=x[1][2]){
				cout<<max(max0+(x[1][0]+x[1][1]+x[1][2])-max1-min1,max1+(x[0][0]+x[0][1]+x[0][2]-max0-min0))<<endl;
			}
			else if (max0!=x[0][0] && max0!=x[0][1] && max0==x[0][2] && max1!=x[1][0] && max1!=x[1][1] && max1==x[1][2]){
				cout<<max(max0+(x[1][0]+x[1][1]+x[1][2])-max1-min1,max1+(x[0][0]+x[0][1]+x[0][2]-max0-min0))<<endl;
			}
			else{
				cout<<max0+max1<<endl;
			}
		}
		else{
			int sum=0;
			for(int j=0;j<a;j++){
				sum+=max(x[j][0],max(x[j][1],x[j][2]));
			}
			cout<<sum<<endl;
		}
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
} 
