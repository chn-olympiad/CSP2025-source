#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen(" club.in","r",stdin);
	freopen(" club.out","w",stdout);
	
    int n,o;
    cin>>o;
	int sum,one=0,two=0,three=0,key; 
	int mid;
	int a[10000][10000];
	for(int h=0;h<o;h++){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		
		mid=n/2;
		for(int i=0;i<n;i++){
			for(int j;j<3;j++){
				if(mid>one||mid>two||mid>three){
					sum+=max(a[i][j],max(a[i][j+1],a[i][j+2]));
					key=max(a[i][j],max(a[i][j+1],a[i][j+2]));
					if(key==a[i][j]&&mid>one){
						one++;
					}
					else{
						sum+=max(a[i][j+1],a[i][j+2]);
						key=max(a[i][j+1],a[i][j+2]);
						if(key==a[i][j+1]){
							two++;
					}
						if(key==a[i][j+2]){
							three++;
						}
					}
					if(key==a[i][j+1]&&mid>two){
						two++;
					}
						else{
						sum+=max(a[i][j],a[i][j+2]);
						key=max(a[i][j],a[i][j+2]);
						if(key==a[i][j]){
							one++;
					}
						if(key==a[i][j+2]){
							three++;
						}
					}
					
					if(key==a[i][j+2]&&mid>three){
						three++;
					}
					else{
						sum+=max(a[i][j],a[i][j+1]);
						key=max(a[i][j],a[i][j+1]);
						if(key==a[i][j]){
							one++;
					}
						if(key==a[i][j+1]){
							two++;
						}
					}
				}
				}
			}
			cout<<sum;
		}	
		return 0;
	}
	
	fcloes(stdin);
	fcloes(stdout);

