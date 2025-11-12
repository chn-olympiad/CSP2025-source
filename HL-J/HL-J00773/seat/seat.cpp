#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long x,y,pm;
	cin>>x>>y;
	long long n=x*y;
	long long a[100010];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long xrcj=a[0];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(a[i]<=a[j+1+i]){
				int t;
				t=a[i];
				a[i]=a[j+1+i];
				a[j+1+i]=t;
			}
		}
	}
	for(int i=0;i<=n;i++){
		if(a[i]==xrcj){
			pm=i+1;
		}
	}
	long long row=ceil(pm/x)+1,lew;
	if(pm%y==0 and row%2==1){
		lew=y;
	}
	else if(pm%y==0 and row%2==0){
		lew=1;
	}
	else if(pm%y!=0 and row%2==1){
		lew=pm%y;
	}
	
	else{
		lew=y+1-pm%y;
	}
	cout<<row<<" "<<lew;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
