#include<bits/stdc++.h>
using namespace std;
long long a[100005],c=1,r=1,n,m;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		}
	for(int i=0;i<n*m;i++){
		for(int j=i+1;i<n*m+1;j++)
			if(a[j]>a[i]){
				c++;
				if(c>n){
					r++;
					for(int z=0;i<n;z++){
						if(a[j]>a[i]){
							c--;
							if(c==0){
								r++;
								c=1;
								}
							
							}
						}
					}
				}
		
	}
	return 0;
}
