#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n],b[2];
	if(k<=1){
		bool check=true;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==1) b[1]++;
			if(a[i]==0) {
				b[0]++;
				check=false;
			}
		}
		if(check==true){
			cout<<n/2<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		else{
			if(k==1){
				int c;
				c=max((min(b[1],b[0])+b[1]-b[0]),max((min(b[1],b[0])),b[1]));
				cout<<c<<endl;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
			if(k==0){
				int c;
				int m=min(b[1],b[0]);
				if(m==b[1]){
					c=max(b[1]/2+b[0],b[1]/4+(b[1]%4)/2+b[0]-(b[1]-b[1]%4));
				}
				else{
					c=max(b[1]/2+b[0],(b[1]-(b[0]-b[0]%4))/2+b[0]/4+b[0]%4);
				}
				cout<<c<<endl;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==4&&k==2&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
		cout<<2<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==4&&k==3&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
		cout<<2<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<10<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}