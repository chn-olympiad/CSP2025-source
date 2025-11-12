#include<bits/stdc++.h>
using namespace std;
int n;
struct stu{
	int d[3];
}a[12345];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].d[0]>>a[i].d[1]>>a[i].d[2];
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(i!=j&&i!=k&&j!=k){
					
				}
			}
		}
	}
	return 0;
} 
