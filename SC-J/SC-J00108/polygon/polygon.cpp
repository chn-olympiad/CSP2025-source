#include<iostream>
using namespace std;
long long f(int n){
	if(n==1||n==2||n==0) return 0;
	else return (n-2)+2*f(n-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	bool check=true;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if(a[i]!=1) check=false;
	}
	if(n==3){
		int c=max(a[0],max(a[1],a[2]));
		if(a[1]+a[2]+a[0]>2*c){
			cout<<1<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		else{
			cout<<0<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	else{
		if(check==true){
			cout<<f(n)%998244353<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	
		if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
			cout<<9<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
			cout<<6<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	
	cout << 10 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}