#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[105];
	int max=0;
	int cnt=0;
	int c=0;
	for(int i=1;i<=n*m;i++){
	    cin>>a[i];
	    max=a[1];
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]>max){
			cnt++;
		} 
	}
	c=cnt/n;
	if(cnt<n){
		cout<<"1"<<" "<<cnt+1; 
	}
	else{
		if(c%2==0&&cnt%n!=0){
		   cout<<c+1<<" "<<cnt%n+1;
		}
		else{
			if(cnt%n==0){
			   cout<<c+1<<" "<<m;
			}
			else{
			    if(c%2!=0){
					cout<<c<<" "<<c-(c-2)*m+1;
				}
			}
		}
	} 
	fclose(stdin);fclose(stdout);
	return 0;
} 
