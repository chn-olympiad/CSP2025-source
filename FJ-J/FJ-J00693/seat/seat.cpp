#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[150];
int mp[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	int cnt=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]>a[1]){
			cnt++;
		}
	}
	int l=cnt/n;
	if(cnt%n!=0){
		l++;
	}
	int h=0;
	if(l%2==1){
		if(cnt%n==0){
			h=n;
		}
		else{
			h=cnt%n;
		}
	}
	else
	{
		if(cnt%n==0){
			h=1;
		}
		else{
			h=n-cnt%n+1;
		}
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
